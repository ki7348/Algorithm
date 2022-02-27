#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v;
int d[1001];

int main(){
    cin >> n;
    v.push_back(0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i=1;i<=n;i++)
        d[i] = 1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(v[j]<v[i]){
                d[i] = max(d[i],d[j]+1);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout << d[i] << ' ';
    // }
    // cout << '\n';
    int result = 0;
    for(int i=1;i<=n;i++)
        result = max(result,d[i]);
    cout << result << '\n';
}