#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,t;
int d[101][10001];
vector<int> hour;
vector<int> value;

int main() {
    cin >> n >> t;
    hour.push_back(0);
    value.push_back(0);
    for(int i=0;i<n;i++) {
        int x,y;
        cin >> x >> y;
        hour.push_back(x);
        value.push_back(y);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=t;j++){
            if(hour[i] <= j) {
                d[i][j] = max(d[i-1][j],d[i-1][j-hour[i]]+value[i]);
            } else {
                d[i][j] = d[i-1][j];
            }
        }
    }
    cout << d[n][t] << '\n';
}