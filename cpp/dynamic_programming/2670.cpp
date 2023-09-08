#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    double graph[10001];
    double dp[10001];

    for(int i=0;i<n;i++){
        double x;
        cin >> x;
        graph[i] = x;
    }

    dp[0] = graph[0];

    for(int i=1;i<n;i++){
        dp[i] = max(graph[i],dp[i-1] * graph[i]);
    }

    double max_elem = dp[0];
    for(int i=1;i<n;i++){
        max_elem = max(dp[i],max_elem);
    }
    
    printf("%0.3lf", max_elem);
    return 0;

}