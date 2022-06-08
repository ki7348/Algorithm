#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
queue<int> q;
int n;
int s;
int dist[100005];
bool visited[100005];

int main() {
    cin >> n;
    
    for(int i=1;i<=n;i++){
        cin >> dist[i];
    }

    cin >> s;
    int result = 0;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        int next1 = cur + dist[cur];
        if(next1 <= n && !visited[next1]){
            q.push(next1);
            visited[next1] = true;
        }
        int next2 = cur - dist[cur];
        if(next2 >= 1 && !visited[next2]){
            q.push(next2);
            visited[next2] = true;
        }
    }
    for(int i=1;i<=n;i++){
        if(visited[i] == true){
            result++;
        }
    }
    cout << result << '\n';
}