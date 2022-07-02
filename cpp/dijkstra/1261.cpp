#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;
int n,m;
int graph[101][101];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool check[101][101] = {false,};

struct Matrix {
    int walls, x, y;
};

struct compare {
    bool operator() (Matrix & first, Matrix & second){
        return first.walls > second.walls;
    }
};

void dijkstra(int a,int b){
    priority_queue<Matrix,vector<Matrix>,compare> pq; 
    pq.push({0,a,b});
    check[a][b] = 1;
    while(!pq.empty()){
        Matrix cur = pq.top();
        int walls = cur.walls;
        int x = cur.x;
        int y = cur.y;
        pq.pop();
        if(x == n-1 && y == m-1){
            cout << walls << '\n';
            break;
        }
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx > n-1 || dy > m-1 || dx < 0 || dy < 0){
                continue;
            }
            if(check[dx][dy]){
                continue;
            }
            if(graph[dx][dy] == 1){
                check[dx][dy] = 1;
                pq.push({walls+1,dx,dy});
            }else{
                check[dx][dy] = 1;
                pq.push({walls,dx,dy});
            }
        }


    }
}

int main() {
    cin >> m >> n;
    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        for(int j=0;j<m;j++){
            graph[i][j] = temp[j] - '0';
        }
    }
    dijkstra(0,0);

}