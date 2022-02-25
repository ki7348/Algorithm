#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int d[501][501];
vector<vector<int>> v2;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<=i;j++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        v2.push_back(v);
    }
    d[0][0] = v2[0][0];
    // for(int i=1;i<n;i++){
    //     d[i][0] = d[i-1][0] + v2[i][0];
    // }
    // for(int i=1;i<n;i++){
    //     d[i][i] = d[i-1][i-1] + v2[i][i];
    // }
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                d[i][j] = d[i-1][j] + v2[i][j];
            }else if(i==j){
                d[i][j] = d[i-1][j-1] + v2[i][j];
            }else{
                d[i][j] = max(d[i-1][j-1],d[i-1][j]) + v2[i][j];
            }
        }
    }
    int max_elem = 0;
    for(int i=0;i<n;i++){
        max_elem = max(max_elem,d[n-1][i]);
    }
    cout << max_elem << '\n';
}