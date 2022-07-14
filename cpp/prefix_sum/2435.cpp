#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int graph[200];
int prefix_sum[200];
int n,k;

int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> graph[i];
        prefix_sum[i] = prefix_sum[i-1] + graph[i];
    }
    int result = -1e9;
    for(int i=k;i<=n;i++){
        result = max(result,prefix_sum[i] - prefix_sum[i-k]);
    }
    cout << result << '\n';
}