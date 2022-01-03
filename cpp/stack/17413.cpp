#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    string str;
    getline(cin,str);

    stack<char> s;
    vector<char> result;

    bool is_reversed = false;
    for(int i=0;i<str.length();i++){
        if(str[i]=='<'){
            is_reversed = true;
            while(!s.empty()){
                result.push_back(s.top());
                s.pop();
            }
        }else if(str[i]=='>'){
            is_reversed = false;
        }else if(str[i]==' '){
            while(!s.empty()){
                result.push_back(s.top());
                s.pop();
            }
            result.push_back(str[i]);
        }
        if(!is_reversed && str[i]!='>' && str[i]!=' '){
            s.push(str[i]);
        }else if(str[i]!=' '&&(is_reversed || str[i]=='>')){
            result.push_back(str[i]);
        }
    }
    while(!s.empty()){
        result.push_back(s.top());
        s.pop();
    }
    for(int i = 0; i<result.size();i++){
        cout << result[i];
    }
}