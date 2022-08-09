#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int m,n,k;
int graph[101][101];
bool check[101][101];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

int bfs(int i,int j){
    queue<pair<int,int>> q;
    check[i][j] = true;
    q.push({i,j});
    int dist = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];

            if(check[dx][dy]) continue;
            if(dx > n-1 || dy > m-1 || dx < 0 || dy < 0) continue;

            check[dx][dy] = true;
            dist += 1;
            q.push({dx,dy});
        }
    }
    return dist;
}

int main() {
    cin >> n >> m >> k;
    for(int i=0;i<k;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        for(int j=a;j<c;j++){
            for(int k=b;k<d;k++){
                check[k][j] = true;
            }
        }
    }

    vector<int> result;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!check[i][j]){
                result.push_back(bfs(i,j));
            }
        }
    }

    cout << result.size() << '\n';
    sort(result.begin(),result.end());
    for(int i=0;i<result.size();i++){
        cout << result[i] << ' ';
    }
    return 0;
}