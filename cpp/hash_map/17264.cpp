#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int n,p;
    cin >> n >> p;
    map<string,char> m;

    int a,b,c;
    cin >> a >> b >> c;
    int total = 0;

    for(int i=0;i<p;i++){
        string name;
        char match;
        cin >> name >> match;
        m[name] = match;
    }
    for(int i=0;i<n;i++){
        string name;
        cin >> name;
        if(m[name] == 'W'){
            total+=a;
        }else{
            if(total>=b){
                total-=b;
            }else{
                total = 0;
            }
        }
        if(total>=c){
            break;
        }
    }
    if(total>=c){
        cout << "I AM NOT IRONMAN!!" << '\n';
    }else{
        cout << "I AM IRONMAN!!" << '\n';
    }
    


}