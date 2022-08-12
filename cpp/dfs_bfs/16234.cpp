#include <iostream>
#include <algorithm>
#include <queue>
#include<string.h>

using namespace std;

int n,l,r;
int graph[101][101];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
vector<pair<int,int>> changed;
bool isCntChanged;


int bfs(int x, int y, bool check[101][101]){
    queue<pair<int,int>> q;

    check[x][y] = true;
    q.push({x,y});
    int sum = graph[x][y];
    changed.push_back({x,y});

    int idx = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(check[dx][dy]) continue;

            if(dx > n-1 || dy > n-1 || dx < 0 || dy < 0) continue;

            int diff = abs(graph[dx][dy] - graph[x][y]);

            if(diff >= l && diff <= r){
                check[dx][dy] = true;
                q.push({dx,dy});
                changed.push_back({dx,dy});
                sum+=graph[dx][dy];
                idx++;
                isCntChanged = true;
            }
        }
    }

    return sum / idx;
}

int main() {
    cin >> n >> l >> r;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> graph[i][j];
        }
    }
    int final_result = 0;

    while(true){
        bool check[101][101];
        memset(check, false, sizeof(check));

        isCntChanged = false;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!check[i][j]){
                    changed.clear();
                    int target_val =  bfs(i,j, check);
                    for(int k=0;k<changed.size();k++){
                        int first_val = changed[k].first;
                        int second_val = changed[k].second;
                        graph[first_val][second_val] = target_val;
                    }
                }
            }
        }

        final_result++;

        if(!isCntChanged){
            break;
        }
    }

    cout << final_result - 1 << '\n';
}