#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,m;
vector<int> day;
vector<int> chap;
int d[21][301];

int main(){
    cin >> n >> m;
    day.push_back(0);
    chap.push_back(0);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        day.push_back(a);
        chap.push_back(b);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(chap[i]<=j){
                d[i][j] = max(d[i-1][j],d[i-1][j-day[i]]+chap[i]);
            }else{
                d[i][j] = d[i-1][j];
            }   
        }
    }
    cout << d[7][7] << '\n';
}