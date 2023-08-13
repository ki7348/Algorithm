#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;

    int answer = 0;

    map<string,int> mp;
    vector<string> v;

    for(int i=0;i<n;i++){
        string str;
        cin >> str;

        mp[str] = i;
    }

    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        v.push_back(str);
    }

    for(int i=0;i<v.size();i++){
        string target = v[i];

        bool state = false;

        for(int j=i+1;j<v.size();j++){
            string compare = v[j];
            if(mp[v[i]] > mp[v[j]]){
                state = true;
                break;
            }
        }

        if(state){
            answer++;
        }
    }

    cout << answer << '\n';

}