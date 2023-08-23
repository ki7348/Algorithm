#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>

using namespace std;

int main(){
    string str;
    cin >> str;
    map<char, int> mp;
    map<char,bool> check;
    deque<char> dq;

    vector<char> v;
    for(int i=0;i<str.length();i++){
        v.push_back(str[i]);
        mp[str[i]] += 1;
    }

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int odd = 0;

    for(int i=0;i<v.size();i++){
        char elem = v[i];
        if(check[elem]){
            continue;
        }
        check[elem] = true;
        if(mp[elem] % 2 == 0){
            for(int j=0;j<mp[elem]/2;j++){
                dq.push_front(elem);
                dq.push_back(elem);
            }
        }else{
            if(odd > 0){
                cout << "I'm Sorry Hansoo" << '\n';
                return 0;
            }
            dq.insert(dq.begin()+dq.size()/2,elem);
            for(int j=0;j<(mp[elem]-1)/2;j++){
                dq.push_front(elem);
                dq.push_back(elem);
            }
            odd++;
        }
    }

    string ans = "";
    for(int i=0;i<dq.size();i++){
        ans+=dq[i];
    }
    cout << ans << '\n';


}