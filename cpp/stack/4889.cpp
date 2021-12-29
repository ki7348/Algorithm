#include <iostream>
#include <stack>

using namespace std;

int main(){
    int set = 1;
    while(true){
        string str;
        cin >> str;
        stack<char> s;
        int answer = 0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='{'){
               s.push('{');
            }
            else if(str[i]=='}'){
                if(s.empty()||s.top()!='{'){
                    s.push('}');
                }else{
                    s.pop();
                }
            }else{
                return 0;
            }
        }
        while(!s.empty()){
            char temp = s.top();
            s.pop();
            if (s.top()!=temp){
                answer+=2;
            }else{
                answer+=1;
            }
            s.pop();
        }

        cout << set++ << ". " << answer << '\n';
    }
}