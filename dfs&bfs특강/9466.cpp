#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int t;
bool visited[100001] = {false,};
bool finished[100001] = {false,};
int graph[100001];
vector<int> result;

void dfs(int x) {
    visited[x] = true;
    int y = graph[x];
    if(!visited[y]){
        dfs(y);
    }else if(!finished[y]){
        while(y!=x){
            result.push_back(y);
            y = graph[y];
        }
        result.push_back(x);
    }
    finished[x] = true;
}

int main(){
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        fill(visited,visited+100001,false);
        fill(finished,finished+100001,false);
        fill(graph,graph+100001,0);
        result.clear();
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
        
        cout << n - result.size() << '\n';
    }
}