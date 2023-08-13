#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main(){
    int k,l;

    cin >> k >> l;

    map<string,int> mp;

    queue<string> q;

    for(int i=0;i<l;i++){
        string str;
        cin >> str;

        mp[str] += 1;
        q.push(str);
    }

    while(!q.empty() && k > 0){
        string data = q.front();
        q.pop();

        if(mp[data] > 1){
            mp[data] -= 1;
            continue;
        }

        cout << data << '\n';
        k--;

    }

}