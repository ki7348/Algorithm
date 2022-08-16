#include <iostream>
#include <algorithm>
#include <queue>

struct Matrix {
    int x,y,d;
};

using namespace std;
int n,m,r,c,d;
int graph[51][51];
bool check[51][51];
int result = 0;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int find_next_d (int d){
    if(d == 0){
        return 3;
    }
    if(d == 1){
        return 0;
    }
    if(d == 2){
        return 1;
    }
    if(d == 3){
        return 2;
    }
    return 0;
}

int find_next_x (int d,int x){
    if(d == 0 || d == 2){
        return x;
    }
    if(d == 1){
        return x-1;
    }
    if(d == 3){
        return x+1;
    }
    return 0;
}

int find_next_y (int d,int y){
    if(d == 1 || d == 3){
        return y;
    }
    if(d == 0){
        return y-1;
    }
    if(d == 2){
        return y+1;
    }
    return 0;
}

int bfs(int x,int y, int d){
    check[x][y] = 1;
    queue<Matrix> q;
    q.push({x,y,d});

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        q.pop();


        int new_d = 0;
        int dx = 0;
        int dy = 0;
        int bx = 0;
        int by = 0;

        if(d == 0){
            new_d = find_next_d(0);
            dx = find_next_x(0,x);
            dy = find_next_y(0,y);
            bx = x+1;
            by = y;
        } else if(d == 1){
            new_d = find_next_d(1);
            dx = find_next_x(1,x);
            dy = find_next_y(1,y);
            bx = x;
            by = y-1;
        } else if(d == 2){
            new_d = find_next_d(2);
            dx = find_next_x(2,x);
            dy = find_next_y(2,y);
            bx = x-1;
            by = y;
        } else {
            new_d = find_next_d(3);
            dx = find_next_x(3,x);
            dy = find_next_y(3,y);
            bx = x;
            by = y+1;
        }

        if(!check[dx][dy] && graph[dx][dy] == 0){
            q.push({dx,dy,new_d});
            check[dx][dy] = 1;
            result++;
        }else{
            int idx = 3;
            bool state = false;
            int next_d = new_d;
            while(idx--){
                int new_new_d = find_next_d(next_d);
                int new_dx = find_next_x(next_d, x);
                int new_dy = find_next_y(next_d, y);
                if(!check[new_dx][new_dy] && graph[new_dx][new_dy] == 0){
                    q.push({new_dx,new_dy,new_new_d});
                    check[new_dx][new_dy] = 1;
                    state = true;
                    result++;
                    break;
                } else {
                    next_d = find_next_d(next_d);
                }
            }
            if(!state){
                if(graph[bx][by] == 0){
                    q.push({bx,by,d});
                }else{
                    break;
                }
            }
        }

    }

    return result;
}

int main() {
    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> graph[i][j];
        }
    }
    cout << bfs(r,c,d) + 1<< '\n';
}