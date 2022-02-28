#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,t;
vector<int> chapter;
vector<int> hour;
int d[101][10001];

int main(){
    cin >> n >> t;
    chapter.push_back(0);
    hour.push_back(0);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        chapter.push_back(a);
        hour.push_back(b);
    }
    for(int i=1;i<chapter.size();i++){
        for(int j=1;j<=t;j++){
            if(chapter[i]<=j){
                d[i][j] = max(hour[i]+d[i-1][j-chapter[i]],d[i-1][j]);
            }else{
                d[i][j] = d[i-1][j];
            }
        }
    }
    cout << d[n][t] << '\n';
}