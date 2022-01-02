#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    deque<int> dq;
    deque<int> result;
    vector<int> command;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        command.push_back(a);
    }
    for(int i=0;i<n;i++){
        dq.push_back(i+1);
    }
    for(int i=n-1;i>=0;i--){
        if(command[i]==1){
            result.push_front(dq.front());
            dq.pop_front();
        }else if(command[i]==2){
            int temp = result.front();
            result.pop_front();
            result.push_front(dq.front());
            result.push_front(temp);
            dq.pop_front();
        }else if(command[i]==3){
            result.push_back(dq.front());
            dq.pop_front();
        }
    }
    for(int i=0;i<n;i++){
        cout <<  result[i] << ' ';
    }

}