#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(){
    int n,k,m;
    cin >> n >> k >> m;
    deque<int> dq;
    vector<int> v;
    for(int i=0;i<n;i++){
        dq.push_back(i+1);
    }
    int cnt = 0;
    bool state = false;
    while(!dq.empty()){
        if(!state){
            for(int i=0;i<k-1;i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
            v.push_back(dq.front());
            dq.pop_front();
        }else{
            for(int i=0;i<k-1;i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
            v.push_back(dq.back());
            dq.pop_back();
        }
        cnt++;
        if(cnt%m==0){
            state=!state;
        }
    }
    for(int i=0;i<v.size();i++){
        cout << v[i] << '\n';
    }
}