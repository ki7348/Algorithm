#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
vector<int> weight;
vector<int> value;
int d[101][100001];

int main(){
    cin >> n >> k;
    weight.push_back(0);
    value.push_back(0);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        weight.push_back(a);
        value.push_back(b);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(weight[i]<=j){
                d[i][j] = max(d[i-1][j],d[i-1][j-weight[i]]+value[i]);
            }else{
                d[i][j] = d[i-1][j];
            }
        }
    }
    cout << d[n][k] << '\n';
}