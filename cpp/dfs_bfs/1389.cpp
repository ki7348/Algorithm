#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int n,m;
vector<int> graph[101];

int bfs(int start){
    queue<pair<int,int>> q;
    bool check[101];
    fill(check, check+101, false);
    q.push({start,0});
    check[start] = 1;

    int dist[n+1];
    fill(dist,dist+n+1,0);

    while(!q.empty()){
        int cur = q.front().first;
        int val = q.front().second;
        q.pop();

        dist[cur] = val;

        for(int i=0;i<graph[cur].size();i++){
            if(check[graph[cur][i]])
                continue;
            check[graph[cur][i]] = true;
            q.push({graph[cur][i],val+1});
        }

    }

    int result = 0;

    for(int i=1;i<n+1;i++){
        result+=dist[i];
    }
    
    return result;
}

int main() {
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int answer = 1e9;
    int index = 0;

    for(int i=1;i<n+1;i++){
        if(answer > bfs(i)){
            answer = bfs(i);
            index = i;
        }
    }

    cout << index << '\n';
}