#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,k;
int graph[11][11];
bool check[11];
vector<int> v;
int result = 1e9;

void back_tracking(int index){
    if(index == n){
        if(v[0] != k){
            return;
        }
        int dist = 0;
        for(int i=0;i<v.size()-1;i++){
            dist += graph[v[i]][v[i+1]];
        }
        result = min(result,dist);
        return;
    }
    for(int i=0;i<n;i++){
        if(check[i]){
            continue;
        }
        check[i] = true;
        v.push_back(i);
        back_tracking(index+1);
        v.pop_back();
        check[i] = false;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> graph[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
            }
        }
    }
    back_tracking(0);
    cout << result << '\n';
}
