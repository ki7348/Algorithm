#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    queue<int> q;
    while(1){
        int x;
        cin >> x;
        if(x==-1){
            break;
        }else if(x!=-1 && x!=0){
            if(q.size()<n){
                q.push(x);
            }
        }else if(x==0){
            q.pop();
        }
    }
    if(q.size()==0){
        cout << "empty";
    }else{
        while(!q.empty()){
            cout << q.front() << " ";
            q.pop();
        }
    }
}