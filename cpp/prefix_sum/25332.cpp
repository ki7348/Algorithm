#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int n;
int v1_sum[200001] = {0,};
int v2_sum[200001] = {0,};
map<int,long long> MAP;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        v1_sum[i] = v1_sum[i-1] + x;
    }
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        v2_sum[i] = v2_sum[i-1] + x;
    }
    long long result = 0;
    for(int i=1;i<=n;i++){
        if(v1_sum[i] == v2_sum[i]){
            result++;
        }
        result += MAP[v1_sum[i] - v2_sum[i]];

        MAP[v1_sum[i] - v2_sum[i]]++;
    }
    cout << result << '\n';
}