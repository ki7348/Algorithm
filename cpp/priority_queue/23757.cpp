#include <iostream>
#include <queue>

using namespace std;
int n,m;
bool result = true;

int main() {
    cin >> n >> m;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        pq.push(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        int val = pq.top();
        pq.pop();
        if(x > val){
            result = false;
            break;
        }else{
            val -= x;
            pq.push(val);
        }
    }
    cout << result << '\n';
}