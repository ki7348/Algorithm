#include <iostream>
#include <algorithm>
#include <vector>
#include  <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> v;

    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        v.push_back(str);
    }

    for(int i=1;i<=v[0].length();i++){
        map<string,int> mp;
        int cnt = 0;
        for(int j=0;j<v.size();j++){
            string substr = v[j].substr(v[j].length()-i,i);
            if(mp[substr]){
                break;
            }
            mp[substr] += 1;
            cnt++;
        }
        if(cnt == v.size()){
            cout << i << '\n';
            return 0;
        }
    }
}