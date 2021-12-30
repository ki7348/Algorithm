#include <iostream>
#include <stack>

using namespace std;

int main(){
    while (true){
        string str;
        stack<char> s;
        bool state = true;
        getline(cin, str);
        if (str=="."){
            break;
        }
        for(int i=0;i<str.length();i++){
            if(str[i]=='('){
                s.push('(');
            }else if(str[i]=='['){
                s.push('[');
            }else if(str[i]==')'){
                if(!s.empty()&&s.top()=='('){
                    s.pop();
                }else{
                    cout << "no" << '\n';
                    state = false;
                    break;
                }
            }else if(str[i]==']'){
                if(!s.empty()&&s.top()=='['){
                    s.pop();
                }else{
                    cout << "no" << '\n';
                    state = false;
                    break;
                }
            }
        }
        if (state == false){
            continue;
        }
        if(s.empty()){
            cout << "yes" << '\n';
        }else{
            cout << "no" << '\n';
        }
        

    }
}