#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n;
char graph[101][101];
bool check[101][101];
int ordinary = 0;
int odd = 0;
queue<pair<int,int>> q;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(int x,int y,char alpha){
    check[x][y] = 1;
    q.push(make_pair(x,y));
    ordinary++;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0 || dy<0 || dx>n-1 || dy>n-1)
                continue;
            if(!check[dx][dy] && graph[dx][dy]==alpha){
                check[dx][dy] = 1;
                q.push(make_pair(dx,dy));
            }
        }    
    }
}

void bfs2(int x,int y){
    check[x][y] = 1;
    q.push(make_pair(x,y));
    odd++;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0 || dy<0 || dx>n-1 || dy>n-1)
                continue;
            if(!check[dx][dy] && (graph[dx][dy]=='R'||graph[dx][dy]=='G')){
                check[dx][dy] = 1;
                q.push(make_pair(dx,dy));
                }
            }
        }    
    }


void bfs3(int x,int y){
    check[x][y] = 1;
    q.push(make_pair(x,y));
    odd++;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0 || dy<0 || dx>n-1 || dy>n-1)
                continue;
            if(!check[dx][dy] && (graph[dx][dy]=='B')){
                check[dx][dy] = 1;
                q.push(make_pair(dx,dy));
                }
            }
        }    
    }


int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++){
            graph[i][j] = str[j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]=='R'&&!check[i][j]){
                bfs(i,j,'R');
            }else if(graph[i][j]=='B'&&!check[i][j]){
                bfs(i,j,'B');
            }else if(graph[i][j]=='G'&&!check[i][j]){
                bfs(i,j,'G');
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            check[i][j] = false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((graph[i][j]=='R'||graph[i][j]=='G')&&!check[i][j]){
                bfs2(i,j);
            }else if(graph[i][j]=='B'&&!check[i][j]){
                bfs3(i,j);
            }
        }
    }
    cout << ordinary<< ' ' << odd << '\n';
}