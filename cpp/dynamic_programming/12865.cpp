#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, k;
int d[101][100001];

int main() {
    cin >> n >> k;
    vector<int> weight;
    vector<int> value;
    weight.push_back(0);
    value.push_back(0);
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        weight.push_back(x);
        value.push_back(y);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j>=weight[i]){
               d[i][j] = max(d[i-1][j],d[i-1][j-weight[i]]+value[i]); 
            }else{
                d[i][j] = d[i-1][j];
            }
        }
    }
    cout << d[n][k] << '\n';
}