#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i=0;i<t;i++){
        string p;
        cin >> p;
        int n;
        cin >> n;
        string str;
        cin >> str;
        deque<int> q;
        string temp;

        for(int j=0;j<str.length();j++){
            if(str[j] == '['){
                continue;
            }else if('0'<=str[j]&&str[j]<='9'){
                temp += str[j];
            }else if(str[j]==','||str[j]==']'){
                if(!temp.empty()){
                    q.push_back(stoi(temp));
                    temp.clear();
                }
            }
        }
        bool is_reversed = false;
        bool state = false;
        for(int j=0;j<p.length();j++){
            if(p[j]=='R'){
                is_reversed=!is_reversed;
            }else if(p[j]=='D'){
                if(q.empty()){
                    state = true;
                }
                if(state==true){
                    cout << "error" << '\n';
                    break;
                }
                if(is_reversed){
                        q.pop_back();
                }else{
                    q.pop_front();
                }
            }
            
        }if(!is_reversed&&!state&&!q.empty()){
            cout << '[';
            int d_size = q.size();
            for(int j=0;j<d_size-1;j++){
                int temp = q.front();
                cout << temp << ',';
                q.pop_front();
            }
            cout << q.front() << ']' << '\n';
        }else if(is_reversed&&!state&&!q.empty()){
            cout << '[';
            int d_size = q.size();
            for(int j=0;j<d_size-1;j++){
                int temp = q.back();
                cout << temp << ',';
                q.pop_back();
            }
            cout << q.back() << ']' <<'\n';
        }else if(!state&&q.empty()){
            cout << "[]" << '\n';
        }
    }
}