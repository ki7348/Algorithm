#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct queueProps {
    int zindex, first_elem, second_elem;
};

int n,m;
int graph[1001][1001];
int visited[2][1001][1001];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        for(int j=0;j<m;j++){
            graph[i][j] = temp[j] - '0';
        }
    }
    queue<queueProps> q;
    q.push({0,0,0});
    visited[0][0][0] = true;
    while(!q.empty()){
        queueProps now = q.front();
        q.pop();
        int z = now.zindex;
        int x = now.first_elem;
        int y = now.second_elem;
        
        if(x == n-1 && y == m-1){
            cout << visited[z][x][y] << '\n';
            return 0;
        }
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0 || dy<0 || dx>n-1 || dy>m-1)
                continue;
            if(!visited[z][dx][dy] && graph[dx][dy] == 0){
                q.push({z,dx,dy});
                visited[z][dx][dy] = visited[z][x][y] + 1;
            }else if(!visited[z][dx][dy] && graph[dx][dy] == 1 && z == 0){
                q.push({z+1,dx,dy});
                visited[z+1][dx][dy] = visited[z][x][y] + 1;
            }
        }
    }
    cout << -1 << '\n';
}