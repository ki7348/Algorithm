#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;

    priority_queue<int> pq;
    
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        pq.push(x);        
    }

    int time = 0;
    while(pq.size() > 1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int next_a = a - 1;
        int next_b = b - 1;

        if(next_a > 0){
            pq.push(next_a);
        }

        if(next_b > 0){
            pq.push(next_b);
        }

        time++;
    }

    if(!pq.empty())
        time += pq.top();

    if(time > 1440){
        cout << -1 << '\n';
        return 0;
    }

    cout << time << '\n';


}