#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int a, b;
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    map<string,int> m;
    map<int,string> m2;

    for(int i=0;i<a;i++){
        string x;
        cin >> x;
        m[x] = i+1;
        m2[i+1] = x;
    }
    for(int i=0;i<b;i++){
        string x;
        cin >> x;
        if(isdigit(x[0])){
            cout << m2[stoi(x)] << '\n';
        }else{
            cout << m[x] << '\n';
        }
    }
}