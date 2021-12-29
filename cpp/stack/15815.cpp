#include <iostream>
#include <stack>

using namespace std;

int main(){
    string str;
    cin >> str;
    stack<int> s;

    for(int i=0;i<str.length();i++){
        if(str[i]=='+'){
            int b=s.top();
            s.pop();
            int a=s.top();
            s.pop();
            s.push(a+b);
        }
        else if(str[i]=='-'){
            int b=s.top();
            s.pop();
            int a=s.top();
            s.pop();
            s.push(a-b);
        }
        else if(str[i]=='*'){
            int b=s.top();
            s.pop();
            int a=s.top();
            s.pop();
            s.push(a*b);
        }
        else if(str[i]=='/'){
            int b=s.top();
            s.pop();
            int a=s.top();
            s.pop();
            s.push(a/b);
        }
        else{
            int num1 = str[i] - '0';
            s.push(num1);
        }
    }
    cout << s.top();
}