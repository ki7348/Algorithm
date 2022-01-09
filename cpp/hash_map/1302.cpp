#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<string,int> s;
    map<string,int>::iterator iter;

    for(int i=0;i<n;i++){
        string str;
        cin >> str;

        s[str] += 1;
    }
    int max_num = 0;
    string max_str;
    for(iter=s.begin();iter!=s.end();++iter){
        if(iter->second>max_num){
            max_num = iter->second;
            max_str = iter->first;
        }
    }
    cout << max_str << '\n';

}