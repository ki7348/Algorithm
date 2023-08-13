#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int graph[101][101];
long long dp[101][101];

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            graph[i][j] = x;
        }
    }

    dp[0][0] = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j] == 0 || (i == n-1 && j == n-1)){
                continue;
            }
            int dx = graph[i][j] + i;
            if(dx < n){
                dp[dx][j] += dp[i][j];
            }
            int dy = graph[i][j] + j;
            if(dy < n){
                dp[i][dy] += dp[i][j];
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[n-1][n-1] << '\n';
}