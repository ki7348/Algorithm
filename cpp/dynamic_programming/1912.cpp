#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v;
int d[100001];

int main(){
    cin >> n;
    v.push_back(0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    d[1] = v[1];
    int cur = v[1];
    for(int i=2;i<=n;i++){
        cur += v[i];
        cur = max(v[i],cur);
        d[i] = max(cur,d[i-1]);
    }
    cout << d[n] << '\n';
}