#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool check[26][26] = {false};
int graph [26][26];
vector<int> final;
int total;

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x,int y){
    total++;
    check[x][y] = 1;
    for(int i=0; i<4; i++){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx<0 || dy<0 || dx>n-1 || dy>n-1)
            continue;
        if(graph[dx][dy] == 1 && check[dx][dy] == 0){
            dfs(dx, dy);
        }
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<n;j++){
            graph[i][j] = str[j]-'0';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==1 && check[i][j]==0){
                total = 0;
                dfs(i,j);
                final.push_back(total);
            }
        }
    }
    cout << final.size() << '\n';
    sort(final.begin(),final.end());
    for(int i=0;i<final.size();i++){
        cout << final[i] << '\n';
    }
}