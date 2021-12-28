#include <iostream>
#include <stack>

using namespace std;

bool isCheck(string str){
    stack<char> s;

    for(int i = 0; i< str.length();i++){
        if(str[i]=='('){
            s.push(str[i]);
        }
        else{
            if(!s.empty()){
                s.pop();
            }else{
                return false;
            }
        }
    }
    return s.empty();
}

int main(){
    int x;
    cin >> x;

    for(int i = 0; i<x;i++){
        string str;
        cin >> str;
        if(isCheck(str)){
            cout << "YES" << '\n';
        }else{
            cout << "NO" << '\n';
        }
    }
    
}