#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int n,m;
int d[46];
map<int,int> mp;


int main() {
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int x;
        cin >> x;
        mp[x] += 1;
    }
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    for(int i=3;i<=n;i++){
        d[i] = d[i-1] + d[i-2];
    }
    vector<int> v;
    int idx = 0;
    for(int i=1;i<=n;i++){

        if(mp[i] == 0){
            idx++;
        }else{
            v.push_back(idx);
            idx = 0;
        }
    }
    if(idx > 0){
        v.push_back(idx);
    }
    int result = 1;
    for(int i=0;i<v.size();i++){
        result *= d[v[i]];
    }
    cout << result << '\n';
}