#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n,k;
queue<int> q;
bool visited[100001];
int prev_val[100001];
int dist[100001];
int dir[2] = {-1, 1};

int main() {
    cin >> n >> k;
    if(n==k){
        cout << 0 << '\n';
        cout << n << '\n';
        return 0;
    }
    q.push(n);
    visited[n] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == k){
            cout << dist[k] << '\n';
            break;
        }
        for(int i=0;i<2;i++){
            int next = cur + dir[i];
            if(next<0 || 100000<next) continue;
            if(!visited[next]){
                visited[next] = true;
                dist[next] = dist[cur] + 1;
                prev_val[next] = cur;
                q.push(next);
            }
        }
        int next = cur * 2;
        if(next<0 || 100000<next) continue;
        if(!visited[next]){
            visited[next] = true;
            dist[next] = dist[cur] + 1;
            q.push(next);
            prev_val[next] = cur;
        }
    }
    deque<int> result;
    int now = k;
    while(prev_val[now] != n){
        result.push_back(prev_val[now]);
        now = prev_val[now];
    }
    cout << n << ' ';
    while(!result.empty()){
        cout << result.back() << ' ';
        result.pop_back();
    }
    cout << k << ' ';
    cout << '\n';
}