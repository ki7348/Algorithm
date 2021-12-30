#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    stack<pair<int,int>> s;
    int total = 0;

    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        if(a==1){
            int b,c;
            cin >> b >> c;
            s.push(make_pair(b,c));
        }
        if(!s.empty()){
            s.top().second--;
            if(s.top().second==0){
                total+=s.top().first;
                s.pop();
            }
        }
        
    }
    cout << total << '\n';
    return 0;
}