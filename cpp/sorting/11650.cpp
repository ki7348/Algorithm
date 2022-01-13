#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        pq.push(make_pair(x,y));
    }
    while(!pq.empty()){
        cout << pq.top().first << ' ' << pq.top().second << '\n';
        pq.pop();
    }
}