#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    bool state=true;
    for(int i=0;i<m;i++){
        stack<int> s;
        int k;
        cin >> k;
        for(int j=0;j<k;j++){
            int a;
            cin >> a;
            s.push(a);
        }
        int s_size = s.size()-1;
        for(int j=0;j<s_size;j++){
            int a =s.top();
            s.pop();
            int b =s.top();
            if(a>b){
                state=false;
                break;
            }
        }
        if (state == false){
            break;
        }
    }
    if(state==true){
        cout << "Yes";
    }else{
        cout << "No";
    }
}