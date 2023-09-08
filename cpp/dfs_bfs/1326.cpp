#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int graph[10001];
int dist[10001];
bool check[10001];
int a,b;

queue<int> q;

void bfs(int start){
    q.push(start);
    check[start] = 1;
    while(!q.empty()){
        int elem = q.front();
        q.pop();

        if(elem == b){
            return;
        }

        for(int i=elem + graph[elem];i<=n;i+=graph[elem]){
            if(check[i]){
                continue;
            }
            dist[i] = dist[elem] + 1;
            check[i] = true;
            q.push(i);
        }

        for(int i=elem - graph[elem];i>=1;i-=graph[elem]){
            if(check[i]){
                continue;
            }
            dist[i] = dist[elem] + 1;
            check[i] = true;
            q.push(i);
        }


    }

}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        graph[i] = x;
    }

    cin >> a >> b;

    bfs(a);

    if(dist[b] == 0){
        cout << -1 << '\n';
        return 0;
    }

    cout << dist[b] << '\n';
}