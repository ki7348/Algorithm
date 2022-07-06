#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int n,x;
int graph[250001];
int prefix_sum[250001];
map<int,int> mp;

int main() {
    cin >> n >> x;
    for(int i=1;i<=n;i++){
        cin >> graph[i];
        prefix_sum[i] = prefix_sum[i-1] + graph[i];
    }
    int result = 0;

    for(int i=x;i<=n;i++){
        result = max(result,prefix_sum[i] - prefix_sum[i-x]);
        mp[prefix_sum[i] - prefix_sum[i-x]]++;
    }
    if(result == 0){
        cout << "SAD" << '\n';
        return 0;
    }
    cout << result << '\n';
    cout << mp[result] << '\n';
}