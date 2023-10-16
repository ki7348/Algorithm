#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9

using namespace std;

int main(){
    int a,k;
    cin >> a >> k;

    int dp[1000001];
    fill(dp,dp+k,INF);

    dp[k] = 0;

    for(int i=k-1;i>=a;i--){
        if(i+1 <= k){
            dp[i] = min(dp[i],dp[i+1] + 1);
        }
        if(i*2 <= k){
            dp[i] = min(dp[i],dp[i*2] + 1);
        }
    }

    cout << dp[a] << '\n';

    
}