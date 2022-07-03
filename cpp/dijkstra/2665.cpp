#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

struct Matrix{
    int walls, x, y;
};

struct compare {
    bool operator() (Matrix & first, Matrix & second){
        return first.walls > second.walls;
    }
};

using namespace std;
int graph[51][51];
bool visited[51][51];
priority_queue<Matrix,vector<Matrix>,compare> pq; 
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        for(int j=0;j<n;j++){
            graph[i][j] = temp[j] - '0';
        }
    }
    visited[0][0] = true;
    pq.push({0,0,0});
    while(!pq.empty()){
        Matrix cur = pq.top();
        int walls = cur.walls;
        int x = cur.x;
        int y = cur.y;
        pq.pop();
        if(x == n-1 && y == n-1){
            cout << walls << '\n';
            break;
        }
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx > n-1 || dy > n-1 || dx <0 || dy < 0){
                continue;
            }
            if(visited[dx][dy]){
                continue;
            }
            if(graph[dx][dy] == 0){
                visited[dx][dy] = 1;
                pq.push({walls+1,dx,dy});
            }else{
                visited[dx][dy] = 1;
                pq.push({walls,dx,dy});
            }
        }

    }
}