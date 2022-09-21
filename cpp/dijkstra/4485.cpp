#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

struct Struct {
    int x,y,dist;
};

struct compare {
	bool operator()(const Struct& s1, const Struct& s2) {
		return s1.dist > s2.dist;
	}
};

void bfs(int start_x, int start_y, int n, int d[126][126], int graph[126][126], bool check[126][126]){
    priority_queue<Struct, vector<Struct>, compare> pq;
    pq.push({start_x,start_y,graph[0][0]});
    d[start_x][start_y] = graph[0][0];
    check[start_x][start_y] = true;

    while(!pq.empty()){
        int dist = pq.top().dist;
        int now_x  = pq.top().x;
        int now_y = pq.top().y;
        pq.pop();

        if(now_x == n-1 && now_y == n-1){
            break;
        }

        if(dist < d[start_x][start_y]){
            continue;
        }

        for(int i=0;i<4;i++){
            int next_x = now_x + dir[i][0];
            int next_y = now_y + dir[i][1];

            if(check[next_x][next_y]){
                continue;
            }

            if(next_x > n -1 || next_y > n-1 || next_x < 0 || next_y < 0){
                continue;
            }

            int cost = dist + graph[next_y][next_x];

            if(d[next_x][next_y] <= cost){
                continue;
            }

            pq.push({next_x, next_y, cost});
            d[next_x][next_y] = cost;
            check[next_x][next_y] = true;
        }
    }

}

int main() {
    int count = 0;
    while(true){
        count++;
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        int graph[126][126];
        int d[126][126];
        bool check[126][126];
        for(int i=0;i<126;i++){
            for(int j=0;j<126;j++){
                d[i][j] = INF;
                check[i][j] = false;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x;
                cin >> x;
                graph[i][j] = x;
            }
        }

        bfs(0,0,n,d,graph,check);

        cout << "Problem " << count << ':' << ' ' << d[n-1][n-1] << '\n';
    
        
    }
}