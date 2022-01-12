#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    multimap<string,int> m;
    multimap<string,int>::iterator iter;
    for(int i=0;i<n;i++){
        string name;
        cin >> name;
        m.insert(make_pair(name,0));
    }
    for(int i=0;i<n-1;i++){
        string name;
        cin >> name;
        if(m.find(name)->second==0){
            m.erase(m.find(name));
        }
    }
    // for(iter=m.begin();iter!=m.end();iter++){
    //     cout << iter->first << ' ' << iter->second << '\n';
    // }
    for(iter=m.begin();iter!=m.end();iter++){
        if(iter->second==0){
            cout << iter->first << '\n';
        }
    }
}