#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<tuple<int,int,string>,vector<tuple<int,int,string>>,greater<tuple<int,int,string>>> pq;
    for(int i=0;i<n;i++){
        int a;
        string str;
        cin >> a >> str;
        pq.push(make_tuple(a,i,str));
    }
    while(!pq.empty()){
        cout << get<0>(pq.top()) << ' ' << get<2>(pq.top()) << '\n';
        pq.pop();
    }
}