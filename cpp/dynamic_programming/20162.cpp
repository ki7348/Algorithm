#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    int graph[1001];
    int dp[1001];

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        graph[i] = x;
        dp[i] = x;
    }

    int answer = 0;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(graph[i] > graph[j]){
                dp[i] = max(dp[i],dp[j] + graph[i]);
                answer = max(answer,dp[i]);
            }
        }
    }

    cout << answer << '\n';
}