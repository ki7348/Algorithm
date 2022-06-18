#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
int n,m;
int move_fast[101] = {0,};
bool check[101] = {false,};
queue<pair<int,int>> q;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        move_fast[x] = y;
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        move_fast[x] = y;
    }
    q.push({0,1});
    check[1] = true;
    while(!q.empty()){
        int cnt = q.front().first;
        int cur = q.front().second;
        q.pop();
        if(cur == 100){
            cout << cnt << '\n';
            return 0;
        }
        for(int i=1;i<=6;i++){
            int target = cur + i;
            if(target > 100){
                continue;
            }
            if(!check[target] && move_fast[target] != 0){
                q.push({cnt+1,move_fast[target]});
                check[move_fast[target]] = true;
            } else if(!check[target]){
                q.push({cnt+1,target});
                check[target] = true;
            }
        }
    }
}