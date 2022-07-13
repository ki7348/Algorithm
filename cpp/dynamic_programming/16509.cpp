#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Matrix{
    int r,c,ctx;
};
int graph[11][11];
int r1,c1;
int r2,c2;
int dir[8][2] = {{-3,2},{-2,3},{2,3},{3,2},{3,-2},{2,-3},{-2,-3},{-3,-2}};
bool check[11][11];
queue<Matrix> q;

int main() {
    cin >> r1 >> c1;
    cin >> r2 >> c2;
    check[r1][c1] = true;
    q.push({r1,c1,0});
    while(!q.empty()){
        int r = q.front().r;
        int c = q.front().c;
        int ctx = q.front().ctx;

        q.pop();

        if(r == r2 && c == c2){
            cout << ctx << '\n';
            return 0;
        }

        for(int i=0;i<8;i++){
            int dr = r + dir[i][0];
            int dc = c + dir[i][1];
            
            if(dir[i][0] > 0 && dir[i][1] > 0){
                if(r + (dir[i][0] - 1) == r2 && c + (dir[i][1] - 1) == c2){
                    continue;
                }
                if(r + (dir[i][0] - 2) == r2 && c + (dir[i][1] - 2) == c2){
                    continue;
                }
            } else if(dir[i][0] > 0 && dir[i][1] < 0){
                if(r + (dir[i][0] - 1) == r2 && c + (dir[i][1] + 1) == c2){
                    continue;
                }
                if(r + (dir[i][0] - 2) == r2 && c + (dir[i][1] + 2) == c2){
                    continue;
                }
            } else if(dir[i][0] < 0 && dir[i][1] < 0){
                if(r + (dir[i][0] + 1) == r2 && c + (dir[i][1] + 1) == c2){
                    continue;
                }
                if(r + (dir[i][0] + 2) == r2 && c + (dir[i][1] + 2) == c2){
                    continue;
                }
            } else {
                if(r + (dir[i][0] + 1) == r2 && c + (dir[i][1] - 1) == c2){
                    continue;
                }
                if(r + (dir[i][0] + 2) == r2 && c + (dir[i][1] - 2) == c2){
                    continue;
                }
            }









            if(dr > 9 || dc > 8 || dr < 0 || dc < 0){
                continue;
            }
            if(check[dr][dc]){
                continue;
            }
            check[dr][dc] = true;
            q.push({dr,dc,ctx+1});
        }
    }
    cout << -1 << '\n';
    return 0;
}