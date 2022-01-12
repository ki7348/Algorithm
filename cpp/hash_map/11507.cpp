#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    map<char,vector<string>> m;
    bool state = false;
    for(int i=0;i<str.size()/3;i++){
        if(find(m[str[3*i]].begin(),m[str[3*i]].end(),str.substr(3*i+1,2))==m[str[3*i]].end()){
            m[str[3*i]].push_back(str.substr(3*i+1,2));
        }else{
            cout << "GRESKA" << '\n';
            state = true;
            break;
        }
    }
    if(!state){
        cout << 13-m['P'].size() << ' ';
        cout << 13-m['K'].size() << ' ';
        cout << 13-m['H'].size() << ' ';
        cout << 13-m['T'].size() << '\n';
    }
}