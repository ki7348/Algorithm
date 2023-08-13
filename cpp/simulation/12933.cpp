#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
    string str;

    cin >> str;

    map<char,int> mp;

    int answer = 0;
    bool wrong = false;

    for(int i=0;i<str.length();i++){
        char ch = str[i];
        if(ch == 'q'){
            if(mp['k']){
                mp['q'] += 1;
                mp['k'] -= 1;
            }else{
                mp['q'] += 1;
                answer++;
            }
        }else if(ch == 'u'){
            if(mp['q']){
                mp['u'] += 1;
                mp['q'] -= 1;
            }else{
                wrong = true;
            }
        }else if(ch == 'a'){
            if(mp['u']){
                mp['a'] += 1;
                mp['u'] -= 1;
            }else{
                wrong = true;
            }
        }else if(ch == 'c'){
            if(mp['a']){
                mp['c'] += 1;
                mp['a'] -= 1;
            }else{
                wrong = true;
            }
        }else{
            if(mp['c']){
                mp['k'] += 1;
                mp['c'] -= 1;
            }else{
                wrong = true;
            }
        }
    }

    if(mp['q'] || mp['a'] || mp['c'] || mp['u']){
        cout << -1 << '\n';
        return 0;
    }

    if(wrong){
        cout << -1 << '\n';
    }else{
        cout << answer << '\n';
    }
}