#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include<string.h> 

using namespace std;

int graph[6][6];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

struct Comb {
    int r;
    int c;
    int elem;
};

int bfs(int r, int c){
    queue<Comb> q;
    bool check[6][6];
    memset(check,false,sizeof(check));

    q.push({r,c,0});
    check[r][c] = true;



    while(!q.empty()){
        int r = q.front().r;
        int c = q.front().c;
        int elem = q.front().elem;
        q.pop();

        if(graph[r][c] == 1){
            return elem;
        }

        for(int i=0;i<4;i++){
            int dr = r + dir[i][0];
            int dc = c + dir[i][1];

            if(check[dr][dc]){
                continue;
            }

            if(dr > 4 || dc > 4 || dr < 0 || dc < 0){
                continue;
            }

            if(graph[dr][dc] == -1){
                continue;
            }

            check[dr][dc] = true;
            q.push({dr,dc,elem+1});
        }

    }

    return -1;
}

int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int x;
            cin >> x;
            graph[i][j] = x;
        }
    }

    int r,c;
    cin >> r >> c;
    cout << bfs(r,c) << '\n';


}