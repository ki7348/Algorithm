#include <iostream>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

struct Comb {
    int x;
    int y;
    int z;
};

void bfs(int n){
    int x,y,z;
    cin >> x >> y >> z;
    queue<Comb> q;
    int value[61][61][61];
    q.push({x,y,z});

    // memset(value,-1,sizeof(value));

    for(int i=0;i<61;i++){
        for(int j=0;j<61;j++){
            for(int k=0;k<61;k++){
                value[i][j][k] = -1;
            }
        }
    }

    value[x][y][z] = 0;

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();

        if(x == 0 && y == 0 && z == 0){
            break;
        }

        int next_x = max(0,x-9);
        int next_y = max(0,y-3);
        int next_z = max(0,z-1);


        if(value[next_x][next_y][next_z] == -1){
            value[next_x][next_y][next_z] = value[x][y][z] + 1;
            q.push({next_x,next_y,next_z});
        }

        next_x = max(0,x-9);
        next_y = max(0,y-1);
        next_z = max(0,z-3);

        if(value[next_x][next_y][next_z] == -1){
            value[next_x][next_y][next_z] = value[x][y][z] + 1;
            q.push({next_x,next_y,next_z}); 
        }

        next_x = max(0,x-3);
        next_y = max(0,y-9);
        next_z = max(0,z-1);

        if(value[next_x][next_y][next_z] == -1){
            value[next_x][next_y][next_z] = value[x][y][z] + 1;
            q.push({next_x,next_y,next_z}); 
        }

        next_x = max(0,x-3);
        next_y = max(0,y-1);
        next_z = max(0,z-9);

        if(value[next_x][next_y][next_z] == -1){
            value[next_x][next_y][next_z] = value[x][y][z] + 1;
            q.push({next_x,next_y,next_z}); 
        }

        next_x = max(0,x-1);
        next_y = max(0,y-9);
        next_z = max(0,z-3);

        if(value[next_x][next_y][next_z] == -1){
            value[next_x][next_y][next_z] = value[x][y][z] + 1;
            q.push({next_x,next_y,next_z}); 
        }

        next_x = max(0,x-1);
        next_y = max(0,y-3);
        next_z = max(0,z-9);

        if(value[next_x][next_y][next_z] == -1){
            value[next_x][next_y][next_z] = value[x][y][z] + 1;
            q.push({next_x,next_y,next_z}); 
        }

    }

    cout << value[0][0][0] << '\n';

}

int main(){
    int n;
    cin >> n;

    bfs(n);
}