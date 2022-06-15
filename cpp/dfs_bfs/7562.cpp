#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int t;
int dir[8][2] = {{-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {2, 1}, {2, -1}};

int main() {
    cin >> t;
    while(t--){
        int l;
        cin >> l;
        int start_x, start_y;
        cin >>  start_x >> start_y;
        int end_x, end_y;
        cin >> end_x >> end_y;
        
        bool check[301][301] = {false,};
        int graph[301][301] = {0,};
        queue<pair<int,int>> q;
        q.push({start_x,start_y});
        check[start_x][start_y] = 1;
        while(!q.empty()){
            int cur_x = q.front().first;
            int cur_y = q.front().second;
            q.pop();
            if(cur_x == end_x && cur_y == end_y){
                cout << graph[cur_x][cur_y] << '\n';
            }
            for(int i=0;i<8;i++){
                int dx = cur_x + dir[i][0];
                int dy = cur_y + dir[i][1];
                if(dx > l-1 || dy > l-1 || dx < 0 || dy < 0){
                    continue;
                }
                if(check[dx][dy]){
                    continue;
                }
                check[dx][dy] = 1;
                graph[dx][dy] = graph[cur_x][cur_y] + 1;
                q.push({dx,dy});
            }
        }
    }
}