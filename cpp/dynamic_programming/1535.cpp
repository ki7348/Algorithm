#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> life;
vector<int> happy;
int d[21][101];

int main(){
    cin >> n;
    life.push_back(0);
    happy.push_back(0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        life.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        happy.push_back(x);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=100;j++){
            if(life[i]<=j){
                d[i][j] = max(d[i-1][j],d[i-1][j-life[i]]+happy[i]);
            }else{
                d[i][j] = d[i-1][j];
            }
        }
    }
    cout << d[n][99] << '\n';
}