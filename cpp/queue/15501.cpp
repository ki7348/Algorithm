#include <iostream>
#include <deque>
#include <vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 0;

    deque<int> dq;
    vector<int> v;

    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        dq.push_back(a);
    }
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    while(dq.front()!=v.front()){
        int temp = dq.front();
        dq.pop_front();
        dq.push_back(temp);
    }
    for(int i=0;i<n;i++){
        if(dq[i]==v[i]){
            count++;
        }
    }
    if(count == n){
        cout << "good puzzle";
        return 0;
    }else{
        count = 0;
        reverse(dq.begin(),dq.end());
        while(dq.front()!=v.front()){
            int temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);
        }
        for(int i=0;i<n;i++){
            if(dq[i]==v[i]){
                count++;
            }
        }
        if(count == n){
            cout << "good puzzle";
        }else{
            cout << "bad puzzle";
        }
    }
}