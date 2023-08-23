#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n,k,a,b;
    cin >> n >> k >> a >> b;

    queue<int> q;
    for(int i=0;i<n;i++){
        q.push(k);
    }

    int day = 1;
    while(true){
        for(int i=0;i<a;i++){
            int temp = q.front();
            q.pop();
            temp += b;
            q.push(temp);
        }

        int cur = n;
        while(cur--){
            int front = q.front();
            q.pop();
            if(front - 1 <= 0){
                cout << day << '\n';
                return 0;
            }
            front -= 1;
            q.push(front);
        }

        day++;
    }

}