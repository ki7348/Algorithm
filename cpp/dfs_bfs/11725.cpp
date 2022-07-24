#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n;
vector<int> graph[100001];
queue<int> q;
int parent[100001];
bool check[100001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    q.push(1);
    parent[1] = 0;
    check[1] = true;
    while(!q.empty()){
        int cur = q.front();

        q.pop();
        for(int i=0;i<graph[cur].size();i++){
            if(!check[graph[cur][i]]){
                parent[graph[cur][i]] = cur;
                q.push(graph[cur][i]);
                check[graph[cur][i]] = true;
            }
        }        
    }
    for(int i=2;i<=n;i++){
        cout << parent[i] << '\n';
    }
}