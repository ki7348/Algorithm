#include <iostream>
#include <algorithm>

using namespace std;
int d,k;
long long dp[31];

void solve(){
    for(int i=1;i<=100000;i++){
        for(int j=1;j<=100000;j++){
            dp[1] = i;
            dp[2] = j;
            for(int k=3;k<=d;k++){
                dp[k] = dp[k-1] + dp[k-2];
            }
            if(dp[d]==k){
                return;
            }
        }
    }
}

int main(){
    cin >> d >> k;
    solve();
    cout << dp[1] << '\n' << dp[2] << '\n';
}