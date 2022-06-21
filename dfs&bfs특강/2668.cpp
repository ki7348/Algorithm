#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n;
bool visited[101] = {false,};
bool finished[101] = {false,};
int graph[101] = {0,};
vector<int> v;

void dfs(int x) {
    visited[x] = true;
    int y = graph[x];
    if(!visited[y]){
        dfs(y);
    }else if(!finished[y]){
        while(y!=x){
            v.push_back(y);
            y = graph[y];
        }
        v.push_back(x);
    }
    finished[x] = true;
}

int main() {
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        graph[i] = x;
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    cout << v.size() << '\n';
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout << v[i] << '\n';
    }
}