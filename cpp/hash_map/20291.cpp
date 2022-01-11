#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<string,int> m;
    map<string,int>::iterator iter;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        string first;
        string second;

        stringstream ss(str);
        getline(ss,first,'.');
        getline(ss,second,'.');
        
        m[second] += 1;
    }
    for(iter=m.begin();iter!=m.end();iter++){
        cout << iter->first << ' ' << iter->second << '\n';
    }
}