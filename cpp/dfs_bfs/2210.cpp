#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

struct Matrix{
    int x,y;
    string str;
};

int graph[6][6];
bool visited[6][6];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
set<string> SET;
queue<Matrix> q;

void bfs(int a, int b) {
    q.push({a,b,""});
    while(!q.empty()){
        Matrix cur = q.front();
        int x = cur.x;
        int y = cur.y;
        string str = cur.str;
        q.pop();

        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];

            if(dx >= 5 || dy >= 5 || dx < 0 || dy < 0){
                continue;
            }
            string new_str = str + to_string(graph[dx][dy]);
            if(new_str.length()==6){
                SET.insert(new_str);
            }else{
                q.push({dx,dy,new_str});
            }
        }
    }
}

int main() {
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int x;
            cin >> x;
            graph[i][j] = x;
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            
            bfs(i,j);
        }
    }
    
    cout << SET.size() << '\n';
}