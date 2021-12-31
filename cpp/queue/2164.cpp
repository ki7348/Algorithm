#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    queue<int> q;

    for(int i=0;i<n;i++){
        q.push(i+1);
    }
    bool state = false;
    while(q.size()>1){
        if(!state){
            q.pop();
        }else{
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        state = !state;
    }
    cout << q.front();
}