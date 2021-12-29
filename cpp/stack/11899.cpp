#include <iostream>
#include <stack>

using namespace std;

int main(){
    string str;
    cin >> str;

    stack<char> s;
    int ans = 0;

    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            s.push('(');
        }else{
            if(s.empty()){
                ans+=1;
            }else{
                s.pop();
            }
        }
    }
    ans+=s.size();
    cout << ans;
}