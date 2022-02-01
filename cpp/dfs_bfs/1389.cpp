#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n,m;
int graph[5001][5001];
int check[5001];
vector<int> v;
queue<int> q;

int bfs(int x){
    q.push(x);
    int temp = 0;
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(graph[x][i]!=0 && !check[i]){
                q.push(i);
                check[i] = check[x]+1;
            }
        }
    }
    for(int i=0;i<5001;i++){
        temp+=check[i];
    }
    return temp;
}

void reset(){
    for(int i=0;i<5001;i++){
        check[i] = 0;
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        graph[x][y] = graph[y][x] = 1;
    }
    for(int i=1;i<=n;i++){
        v.push_back(bfs(i));
        reset();
    }
    int min_elem = *min_element(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(v[i] == min_elem){
            cout << i + 1 << '\n';
            return 0;
        }
    }
}