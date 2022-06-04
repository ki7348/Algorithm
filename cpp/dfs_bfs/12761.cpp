#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int a,b,n,m;
bool visited[100001];
int dist[100001];
queue<int> q;

int main() {
    cin >> a >> b >> n >> m;
    q.push(n);
    visited[n] = true;
    dist[n] = 0;
    int dir[8] = {1, -1, a, b, -a, -b, a, b};
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == m){
            cout << dist[m] << '\n';
            break;
        }
        for(int i=0;i<6;i++){
            int next = cur + dir[i];
            if(next<0 || 100000<next) continue;
            if(!visited[next]){
                visited[next] = true;
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
        for(int i=6;i<8;i++){
            int next = cur * dir[i];
            if(next<0 || 100000<next) continue;
            if(!visited[next]){
                visited[next] = true;
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
}