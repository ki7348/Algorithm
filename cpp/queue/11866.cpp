#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    queue<int> q;
    vector<int> v;
    int cnt = 1;
    for(int i=0;i<n;i++){
        q.push(i+1);
    }
    while(q.size()!=0){
        if(cnt%k==0){
            int temp = q.front();
            q.pop();
            v.push_back(temp);
        }else{
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        cnt++;
    }
    cout << '<';
    for(int i=0;i<v.size()-1;i++){
        cout << v[i] << ", ";
    }
    cout << v.back() << '>';

}