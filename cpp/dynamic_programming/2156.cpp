#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> v;
int d[10001];

int main(){
    cin >> n;
    v.push_back(0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    d[1] = v[1];
    d[2] = v[1] + v[2];
    d[3] = max(v[1]+v[2],v[1]+v[3]);
    d[3] = max(d[3],v[2]+v[3]);
    for(int i=4;i<=n;i++){
        d[i] = max(v[i]+d[i-2],v[i]+v[i-1]+d[i-3]);
        d[i] = max(d[i],d[i-1]);
    }
    int result = 0;
    for(int i=1;i<=n;i++){
        result = max(result,d[i]);
    }
    cout << result << '\n';

}