#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n,m;
int graph[9][9];
int new_graph[9][9];
bool check[9][9];
vector<pair<int,int>> v;
vector<int> graph_temp;
vector<vector<int>> graph_index;
vector<int> graph_index_individual;
bool check_graph[100];
queue<pair<int,int>> q;
int final = 0;

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(int x,int y){
    int temp_cnt = 0;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0 || dy<0 || dx>n-1 || dy>m-1)
                continue;
            if(!check[dx][dy] && graph[dx][dy]==0){
                check[dx][dy] = 1;
                graph[dx][dy] = 2;
                q.push(make_pair(dx,dy));
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j] == 0){
                temp_cnt++;
            }
        }
    }
    return temp_cnt;
}

void back_tracking(int index,int idx){
    if(index == 3){
        for(int i=0;i<3;i++){
            graph_index_individual.push_back(graph_temp[i]);
        }
        graph_index.push_back(graph_index_individual);
        graph_index_individual.pop_back();
        graph_index_individual.pop_back();
        graph_index_individual.pop_back();
        return;
    }
    for(int i=idx;i<v.size();i++){
        if(check_graph[i])
            continue;
        check_graph[i] = true;
        graph_temp.push_back(i);
        back_tracking(index+1,i);
        graph_temp.pop_back();
        check_graph[i] = false;
    }
}

void reset(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            check[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<9;j++){
            graph[i][j] = new_graph[i][j];
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin >> x;
            graph[i][j] = x;
            new_graph[i][j] = x;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]==0){
                v.push_back(make_pair(i,j));
            }
        }
    }
    sort(v.begin(),v.end());
    back_tracking(0,0);
    for(int i=0;i<graph_index.size();i++){
        for(int j=0;j<3;j++){
            graph[v[graph_index[i][j]].first][v[graph_index[i][j]].second] = 1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(graph[i][j]==2){
                    q.push(make_pair(i,j));
                }
            }
        }
        final = max(final,bfs(0,0));
        reset();
    }
    // for(int i=0;i<graph_index.size();i++){
    //     for(int j=0;j<3;j++){
    //         cout << graph_index[i][j] << ' ';
    //     }
    //     cout << '\n';   
    // }
    cout << final << '\n';
}