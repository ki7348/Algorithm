#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int d[1500002];
vector<pair<int,int>> v;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    fill(d,d+1500002,0);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    for(int i=v.size()-1;i>=0;i--){
        if(i+v[i].first>n){
            d[i] = d[i+1];
        }else{
            d[i] = max(d[i+v[i].first]+v[i].second,d[i+1]);
        }
    }
    int max_elem = 0;
    for(int i=0;i<1500002;i++){
        max_elem = max(max_elem,d[i]);
    }
    cout << max_elem << '\n';
}