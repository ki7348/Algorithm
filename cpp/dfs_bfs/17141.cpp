#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n,m;
int graph[51][51];
int new_graph[51][51];
bool check[51][51];
bool back_tracking_check[11];
vector<int> temp;
vector<int> graph_individual;
vector<vector<int>> graph_index;
vector<pair<int,int>> v;
queue<pair<int,int>> q;

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void back_tracking(int index,int idx){
    if(index==m){
        for(int i=0;i<m;i++){
            graph_individual.push_back(temp[i]);
        }
        graph_index.push_back(graph_individual);
        graph_individual.clear();
        return;
    }
    for(int i=idx;i<v.size();i++){
        if(back_tracking_check[i])
            continue;
        back_tracking_check[i] = true;
        temp.push_back(i);
        back_tracking(index+1,i);
        temp.pop_back();
        back_tracking_check[i] = false;
    }
}

int bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0 || dy<0 || dx>n-1 || dy>n-1)
                continue;
            if(!check[dx][dy]){
                check[dx][dy] = 1;
                q.push(make_pair(dx,dy));
                graph[dx][dy] = graph[x][y] + 1;
            }
        }
    }
    int max_elem = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            max_elem = max(max_elem,graph[i][j]);
        }
    }
    return max_elem;
}

void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j] = new_graph[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==1){
                check[i][j] = 1;
            }else{
                check[i][j] = 0;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            graph[i][j] = x;
            new_graph[i][j] = x;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==1){
                check[i][j] = 1;
                graph[i][j] = 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==2){
                v.push_back(make_pair(i,j));
            }
        }
    }
    back_tracking(0,0);
    int result = 999999;
    for(int i=0;i<graph_index.size();i++){
        for(int j=0;j<m;j++){
            q.push(make_pair(v[graph_index[i][j]].first,v[graph_index[i][j]].second));
            check[v[graph_index[i][j]].first][v[graph_index[i][j]].second] = 1;
            graph[v[graph_index[i][j]].first][v[graph_index[i][j]].second] = 0;
        }
        int temp = bfs();
        bool state = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(check[i][j] == false)
                    state = true;
            }
        }
        if(!state){
            result = min(result,temp);
        }
        reset();
    }
    if(result==999999){
        cout << -1 << '\n';
        return 0;
    }
    cout << result << '\n';
}