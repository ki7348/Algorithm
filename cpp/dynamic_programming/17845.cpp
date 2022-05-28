#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,k;
vector<int> imp;
vector<int> hour;
int d[1001][10001];

int main() {
    cin >> n >> k;
    imp.push_back(0);
    hour.push_back(0);
    for(int i=0;i<k;i++){
        int x,y;
        cin >> x >> y;
        imp.push_back(x);
        hour.push_back(y);
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(hour[i]<=j) {
                d[i][j] = max(d[i-1][j], d[i-1][j-hour[i]] + imp[i]);
            } else {
                d[i][j] = d[i-1][j];
            }
        }
    }
    cout << d[k][n] << '\n';
}