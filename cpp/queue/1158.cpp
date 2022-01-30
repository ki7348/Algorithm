#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    queue<int> q;
    vector<int> v;

    for(int i=0;i<n;i++){
        q.push(i+1);
    }

    while(!q.empty()){
        for(int i=0;i<k-1;i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        v.push_back(q.front());
        q.pop();
    }
    cout << '<';
    for(int i=0;i<v.size()-1;i++){
        cout << v[i] << ", ";
    }
    cout << v.back() << '>' << '\n';
}