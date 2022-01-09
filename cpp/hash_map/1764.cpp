#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    int a,b;
    cin >> a >> b;
    map<string,int> m;
    vector<string> v;
    for(int i=0;i<a;i++){
        string x;
        cin >> x;
        m[x] += 1;
    }
    for(int i=0;i<b;i++){
        string x;
        cin >> x;
        if(m[x]>0){
            v.push_back(x);
        }
    }
    cout << v.size() << '\n';
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout << v[i] << '\n';
    }
}