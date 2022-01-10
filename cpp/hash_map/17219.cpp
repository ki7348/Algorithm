#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;

    map<string,string> site;

    for(int i=0;i<n;i++){
        string a, b;
        cin >> a >> b;
        site[a] = b;
    }
    for(int j=0;j<m;j++){
        string find;
        cin >> find;
        cout << site[find] << '\n';
    }
}