#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int dp[100001][3];
int graph[100001][3];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            int x;
            cin >> x;
            graph[i][j] = x;
        }
    }

    for(int i=0;i<3;i++){
        dp[0][i] = graph[0][i];
    }

    for(int i=1;i<n;i++){
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]) + graph[i][0];
        dp[i][1] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2])) + graph[i][1];
        dp[i][2] = max(dp[i-1][1],dp[i-1][2]) + graph[i][2];
    }

    int max_elem = max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));

        for(int i=0;i<3;i++){
        dp[0][i] = graph[0][i];
    }

    for(int i=1;i<n;i++){
        dp[i][0] = min(dp[i-1][0],dp[i-1][1]) + graph[i][0];
        dp[i][1] = min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2])) + graph[i][1];
        dp[i][2] = min(dp[i-1][1],dp[i-1][2]) + graph[i][2];
    }

    int min_elem = min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
    cout << max_elem << ' ' << min_elem << '\n';
}