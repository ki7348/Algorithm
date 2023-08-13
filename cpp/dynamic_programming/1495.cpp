#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool dp[51][1001];
vector<int> v;

int main(){
    int n, s, m;
    cin >> n >> s >> m;
    v.push_back(s);

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    dp[0][s] = true;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j - v[i] >= 0 && dp[i-1][j - v[i]]){ 
                dp[i][j] = true;
            }
            if(j + v[i] <= m && dp[i-1][j + v[i]]){
                dp[i][j] = true;
            }
        }
    }

    int max_val = -1;
    for(int i=0;i<=m;i++){
        if(dp[n][i]){
            max_val = i;
        }
    }

    cout << max_val << '\n';

}