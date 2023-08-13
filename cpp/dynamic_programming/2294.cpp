#include <iostream>
#include <algorithm>
#include <vector>

#define MAXVAL 1e9

using namespace std;

int dp[101][10001];
vector<int> v;

void initDp(){
    for(int i=0;i<101;i++){
        for(int j=0;j<10001;j++){
            if(j == 0){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = MAXVAL;
        }
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    initDp();

    v.push_back(0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j >= v[i]){
                dp[i][j] = min(dp[i][j-v[i]] + 1, dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    if(dp[n][k] == MAXVAL){
        cout << -1 << '\n';
        return 0;
    }
    cout << dp[n][k] << '\n';
}