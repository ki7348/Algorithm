#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

    int n,m;
    vector<pair<int,int>> waiting;
    int graph[1001][1001];
    bool check[1001][1001];
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void bfs(){
    queue<pair<int,int>> q;
    for(int i=0;i<waiting.size();i++){
        int wait_x = waiting[i].first;
        int wait_y = waiting[i].second;
        check[wait_x][wait_y] = 1;
        q.push({wait_x, wait_y});
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];

            if(dx > n-1 || dy > m-1 || dx < 0 || dy < 0){
                continue;
            }

            if(check[dx][dy]){
                continue;
            }

            if(graph[dx][dy] == 0){
                graph[dx][dy] = graph[x][y] + 1;
                check[dx][dy] = 1;
                q.push({dx,dy});
            }
        }   
    }
}

int main(){
    cin >> m >> n;


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin >> x;
            graph[i][j] = x;
        }
    }

    int zeros = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j] == 0){
                zeros += 1;
            }
        }
    }

    if(zeros == 0){
        cout << 0 << '\n';
        return 0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!check[i][j] && graph[i][j] == 1){
                waiting.push_back({i,j});
            }
        }
    }

    bfs();

    int result = -1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            result = max(result, graph[i][j]);
        }
    }


    zeros = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j] == 0){
                zeros += 1;
            }
        }
    }

    if(zeros > 0){
        cout << -1 << '\n';
        return 0;
    }



    cout << result - 1 << '\n';
    
}