#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;

int n;

int graph[1001];
int d[1001];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> graph[i];
    }
    fill(d,d+1000,INF);
    d[0] = 0;
    for(int i=0;i<n;i++){
        if(graph[i] == 0){
            continue;
        }
        for(int j=i+1;j<=i+graph[i];j++){
            if(j<n){
                d[j] = min(d[j],d[i]+1);
            }
        }
    }
    if(d[n-1] == INF){
        cout << -1 << '\n';
        return 0;
    }
    cout << d[n-1] << '\n';
}