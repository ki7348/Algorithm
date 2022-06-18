#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define MAX_VAL 1e9

using namespace std;
long long s,t;
queue<pair<long long,string>> q;
set<long long> SET;
vector<char> v;

int main() {
    cin >> s >> t;
    if(s == t){
        cout << 0 << '\n';
        return 0;
    }
    q.push({s,""});
    while(!q.empty()){
        long long cur = q.front().first;
        string val = q.front().second;
        q.pop();
        if(cur == t){
            cout << val << '\n';
            return 0;
        }
        long long mul = cur * cur;
        if(mul <= MAX_VAL && SET.find(mul) == SET.end()){
            q.push({mul,val + "*"});
            SET.insert(mul);
        }
        long long add = cur + cur;
        if(add <= MAX_VAL && SET.find(add) == SET.end()){
            q.push({add,val + "+"});
            SET.insert(add);
        }
        long long diff = cur - cur;
        if(diff <= MAX_VAL && SET.find(diff) == SET.end()){
            q.push({diff,val + "-"});
            SET.insert(diff);
        }
        if(cur != 0){
            long long div = cur / cur;
            if(div <= MAX_VAL && SET.find(div) == SET.end()){
                q.push({div,val + "/"});
                SET.insert(div);
            }
        }
    }
    cout << -1 << '\n';
}