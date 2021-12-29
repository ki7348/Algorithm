#include <iostream>
#include <stack>

using namespace std;
stack<int> s;

int main(){
    int a;
    cin >> a;

    for (int i = 0; i < a; i++){
        string str;
        cin >> str;

        if (str == "push") {
            int x; 
            cin >> x;
            s.push(x);
        }
        else if (str == "top"){
            if (s.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << s.top() << "\n";
            }
        }
        else if (str == "pop"){
            if (s.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if (str=="size"){
            cout << s.size() << "\n";
        }
        else{
            if (s.empty()){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }

    }



}