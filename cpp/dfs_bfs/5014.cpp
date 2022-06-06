#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int f,s,g,u,d;
bool visited[1000001];
int dist[1000000];
queue<int> q;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> f >> s >> g >> u >> d;
    if(s == g){
        cout << 0 << '\n';
        return 0;
    }
    visited[s] = 1;
    q.push(s);
    int dir[2] = {u, -d};
    if(s>g && d==0){
        cout << "use the stairs" << '\n';
        return 0;
    }
    if(s<g && u==0){
        cout << "use the stairs" << '\n';
        return 0;
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == g){
            cout << dist[cur] << '\n';
            break;
        }
        for(int i=0;i<2;i++){
            int next = cur + dir[i];
            if(next <= 0 || next > f){
                continue;
            }
            if(!visited[next]){
                visited[next] = 1;
                q.push(next);
                dist[next] = dist[cur] + 1;
            }
        }
    }
    if(dist[g] == 0){
        cout << "use the stairs" << '\n';
    }
}