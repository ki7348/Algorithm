#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
int n,m;
int s,e;
vector<int> teleport[300001];
queue<int> q;
bool visited[300001] = {false,};
int dist[300001] = {0,};

int main() {
    cin >> n >> m >> s >> e;
    for(int i = 0;i<m;i++){
        int x,y;
        cin >> x >> y;
        teleport[x].push_back(y);
        teleport[y].push_back(x);
    }
    q.push(s);
    visited[s] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == e){
            cout << dist[cur] << '\n';
            break;
        }
        for(int i=0;i<teleport[cur].size();i++){
            if(visited[teleport[cur][i]]){
                continue;
            }
            visited[teleport[cur][i]] = 1;
            q.push(teleport[cur][i]);
            dist[teleport[cur][i]] = dist[cur] + 1;
        }
        if(!visited[cur - 1] && cur - 1 > 0){
            visited[cur - 1] = 1;
            q.push(cur - 1);
            dist[cur - 1] = dist[cur] + 1;
        }
        if(!visited[cur + 1] && cur + 1 <= n){
            visited[cur + 1] = 1;
            q.push(cur + 1);
            dist[cur + 1] = dist[cur] + 1;
        }
    }

}