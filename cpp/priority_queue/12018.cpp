#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> point;
    int cnt = 0;
    for(int i=0;i<n;i++){
        int p, l;
        cin >> p >> l;
        priority_queue<int, vector<int>, greater<int>> q;
        for(int j=0;j<p;j++){
            int x;
            cin >> x;
            q.push(x);
        }
        if(p>=l){
            for(int j=0;j<p-l;j++){
                q.pop();
            }
            point.push(q.top());
        }else{
            point.push(1);
        }
    }
    for(int i=0;i<n;i++){
        if(point.top()<=m){
            cnt++;
            m-=point.top();
            point.pop();
        }
    }
    cout << cnt << '\n';
}