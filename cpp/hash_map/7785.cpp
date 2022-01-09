#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, int> m;
    map<string,int>::reverse_iterator iter;
    for(int i=0;i<n;i++){
        string a, b;
        cin >> a >> b;
        if(b=="enter"){
            m[a]+=1;
        }else{
            m[a]-=1;
        }
    }
    for(iter=m.rbegin();iter!=m.rend();++iter){
        if(iter->second>0){
            cout << iter->first << '\n';
        }
    }
    
}
