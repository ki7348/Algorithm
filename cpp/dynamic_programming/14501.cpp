#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int d[2000];
vector<pair<int,int>> v;

int main(){
    cin >> n;
    fill(d,d+2000,0);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    for(int i=v.size()-1;i>=0;i--){
        if(i+v[i].first>n){
            continue;
        }
        d[i] = v[i].second;
        for(int j=i+v[i].first;j<n;j++)
            d[i] = max(d[i],d[j] + v[i].second);
    }
    int max_elem = 0;
    for(int i=0;i<2000;i++){
        max_elem = max(max_elem,d[i]);
    }
    cout << max_elem << '\n';
}