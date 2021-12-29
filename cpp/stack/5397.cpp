#include <iostream>
#include <stack>

using namespace std;

int main(){
    int x;
    cin >> x;

    for(int i=0;i<x;i++){
        stack<char> s;
        stack<char> temp;
        string str;
        cin >> str;

        for(int j=0;j<str.length();j++){
            if(str[j]=='<'){
                if(!s.empty()){
                    temp.push(s.top());
                    s.pop();
                }
            }
            else if(str[j]=='>'){
                if(!temp.empty()){
                    s.push(temp.top());
                    temp.pop();
                }
            }
            else if(str[j]=='-'){
                if(!s.empty()){
                    s.pop();
                }
            }
            else{
                s.push(str[j]);
            }
        }
        if(!temp.empty()){
            int temp_size = temp.size();
            for (int j = 0;j<temp_size;j++){
                s.push(temp.top());
                temp.pop();
            }
        }
        int s_size = s.size();
        stack<char> rs;
        for (int j=0;j<s_size;j++){
            rs.push(s.top());
            s.pop();
        }

        int rs_size = rs.size();
        for (int j = 0 ;j<rs_size;j++){
            cout << rs.top();
            rs.pop();
        }
        cout << '\n';
    }
}