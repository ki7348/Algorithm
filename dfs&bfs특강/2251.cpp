#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

struct Matrix {
    int x,y,z;
};

int a,b,c;
queue<Matrix> q;
bool check[501][501][501] = {false,};
vector<int> result;


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    q.push({0,0,c});
    check[0][0][c] = true;

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();

        if(x == 0){
            result.push_back(z);
        }

        // c to a
        if(x + z > a && !check[a][y][x+z-a]) {
            q.push({a,y,x+z-a});
            check[a][y][z-a] = true;
        }else if(x + z <= a && !check[x+z][y][0]){
            q.push({x+z,y,0});
            check[x+z][y][0] = true;
        }

        // c to b
        if(y + z > b && !check[x][b][y+z-b]) {
            q.push({x,b,y+z-b});
            check[x][b][y+z-b] = true;
        }else if(y + z <= b && !check[x][y+z][0]){
            q.push({x,y+z,0});
            check[x][y+z][0] = true;
        }

        // a to b
        if(x + y > b && !check[x+y-b][b][z]) {
            q.push({x+y-b,b,z});
            check[x+y-b][b][z] = true;
        }else if(x + y <= b && !check[0][x+y][z]){
            q.push({0,x+y,z});
            check[0][x+y][z] = true;
        }

        // a to c
        if(x + z > c && !check[x+z-c][y][c]) {
            q.push({x+z-c,y,c});
            check[x+z-c][y][c] = true;
        }else if(x + z <= c && !check[0][y][x+z]){
            q.push({0,y,x+z});
            check[0][y][x+z] = true;
        }

        // b to c
        if(y + z > c && !check[x][y+z-c][c]) {
            q.push({x,y+z-c,c});
            check[x][y+z-c][c] = true;
        }else if(y + z <= c && !check[x][0][y+z]){
            q.push({x,0,y+z});
            check[x][0][y+z] = true;
        }

        // b to a
        if(y + x > a && !check[a][y+x-a][z]) {
            q.push({a,y+x-a,z});
            check[a][y+x-a][z] = true;
        }else if(x + y <= a && !check[x+y][0][z]){
            q.push({x+y,0,z});
            check[x+y][0][z] = true;
        }
    }
    sort(result.begin(),result.end());
    for(int i=0;i<result.size();i++){
        cout << result[i] << ' ';
    }
    cout << '\n';
}