#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MOD 1000000007

using namespace std;
int n,q;
int v[2000];
vector<int> graph[2000];

void bfs(int start, int end){
    queue<pair<int,int>> q;
    bool check[2000] = {false,};
    q.push({v[start],start});
    check[start] = 1;
    while(!q.empty()){
        int val = q.front().first;
        int cur = q.front().second;
        q.pop();
        if(cur == end){
            cout << val << '\n';
            break;
        }
        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i];
            if(next > n || next < 1){
                continue;
            }
            if(check[next]){
                continue;
            }
            int next_val = stoull((to_string(val) + to_string(v[next]))) % MOD;
            
            check[next] = true;
            q.push({next_val,next});
        }
    }
}

int main() {
    
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        bfs(a,b);
    }
}