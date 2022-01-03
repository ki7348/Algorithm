#include <iostream>
#include <deque>

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        deque<char> dq;
        for(int j=0;j<n;j++){
            char ch;
            cin >> ch;
            if(dq.empty()){
                dq.push_back(ch);
            }else{
                if((int)dq.front()>=(int)ch){
                    dq.push_front(ch);
                }else{
                    dq.push_back(ch);
                }
            }
        }
        for(int i=0;i<n;i++){
            cout << dq[i];
        }
        cout << '\n';
    }
}