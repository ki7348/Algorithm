#include <iostream>
#include <stack>

using namespace std;

int main(){
    string initial;
    cin >> initial;

    stack<char> s;
    stack<char> l;

    for(int i = 0; i < initial.length(); i++){
        s.push(initial[i]);
    }

    int x;
    cin >> x;

    for(int i = 0; i < x; i++){
        char input;
        cin >> input;
        if(input == 'P'){
            char next;
            cin >> next;
            s.push(next);
        }
        else if(input == 'L'){
            if(!s.empty()){
                l.push(s.top());
                s.pop();
            }
        }
        else if(input == 'B'){
            if(!s.empty()){
                s.pop();
            }
        }
        else{
            if(!l.empty()){
                char temp = l.top();
                l.pop();
                s.push(temp);
            }
        }
    }
    if(!l.empty()){
        int l_size = l.size();
        for(int i = 0; i < l_size;i++){
            s.push(l.top());
            l.pop();
        }
    }
    int s_size = s.size();
    stack<char> reversed_stack;
    for(int i = 0;i<s_size;i++){
        reversed_stack.push(s.top());
        s.pop();
    }
    int rs_size = reversed_stack.size();
    for(int i = 0;i<rs_size;i++){
        cout << reversed_stack.top();
        reversed_stack.pop();
    }
}