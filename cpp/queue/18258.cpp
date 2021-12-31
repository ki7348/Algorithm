#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);


    queue<int> q;
    string a;
    int b;

    int x;
    cin >> x;

    for(int i=0;i<x;i++){
        cin >> a;
        if(a=="push"){
            cin >> b;
            q.push(b);
        }else if(a=="front"){
            if(q.empty()){
                cout << -1 << '\n';
            }else{
                cout << q.front() << '\n';
            }
        }else if(a=="pop"){
            if(!q.empty()){
                cout << q.front() << '\n';
                q.pop();
            }else{
                cout << -1 << '\n';
            }
        }else if(a=="size"){
            cout << q.size() << '\n';
        }else if(a=="empty"){
            if(q.empty()){
                cout << 1 << '\n';
            }else{
                cout << 0 << '\n';
            }
        }else if(a=="back"){
            if(!q.empty()){
                cout << q.back() << '\n';
            }else{
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}