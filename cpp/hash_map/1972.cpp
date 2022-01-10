#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    string s;
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> s){
        if(s=="*"){
            break;
        }
        int string_len = s.length();
        if(string_len==1||string_len==2){
            cout << s << " is surprising." << '\n';
        }else{
            bool state = true;
            for(int i=1;i<string_len-1;i++){ // 1 2
                map<string,int> m;
                map<string,int>::iterator iter;
                for(int j=0;j<string_len-1;j++){ // 0 1 2
                    if(i+j>=string_len){
                        continue;
                    }
                    string new_char;
                    new_char += s[j];
                    new_char += s[i+j];
                    m[new_char] +=1 ;
                }
                for(iter=m.begin();iter!=m.end();iter++){
                    if(iter->second>1){
                        state = false;
                    }
                }
            }
            if(state == false){
                cout << s << " is NOT surprising." << '\n';
            }else{
                cout << s << " is surprising." << '\n';
            }
        }
    }
}