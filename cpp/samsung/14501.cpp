#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int d[20];
vector<pair<int,int>> v;

int main() {
    cin >> n;
    v.push_back(make_pair(0,0));
    fill(d,d+20,0);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    for(int i=n;i>0;i--) {
        if(i+v[i].first <= n+1)
            d[i] = max(d[i+1],v[i].second + d[i+v[i].first]);
        else {
            d[i] = d[i+1];
        }
    }
    cout << d[1] << '\n';
}