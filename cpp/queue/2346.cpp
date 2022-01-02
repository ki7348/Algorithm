#include <iostream>
#include <deque>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin >> n;
    deque<pair<int,int>> dq;

    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        dq.push_back(make_pair(a,i+1));
    }
    while(!dq.empty()){
        int temp = dq.front().first;
        cout << dq.front().second << ' ';
        dq.pop_front();
        if(temp>0){
            for(int i=0;i<temp-1;i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }else{
            for(int i=temp;i<0;i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        
    }
}