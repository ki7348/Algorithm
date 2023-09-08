#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    int graph[301][301];
    int dp[301][301];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin >> x;
            graph[i][j] = x;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int dist = graph[i][j];
            for(int k=1;k<=dist;k++){
                //아래
                if(i + k < n){
                    dp[i+k][j] = min(dp[i+k][j],dp[i][j] + 1);
                }
                //오른쪽
                if(j + k < m){
                    dp[i][j+k] = min(dp[i][j+k],dp[i][j] + 1);
                }
            }


            
        }
    }

    cout << dp[n-1][m-1] << '\n';
}