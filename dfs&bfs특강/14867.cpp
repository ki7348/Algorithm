#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;
int a,b,c,d;

map<pair<int,int>,int> mp;
queue<pair<int,int>> q;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c >> d;
    mp[{0,0}] = 0;
    q.push({0,0});
    while(!q.empty()){
        int cur_a = q.front().first;
        int cur_b = q.front().second;
        
        q.pop();
        if(cur_a == c && cur_b == d){
            cout << mp[{cur_a,cur_b}] << '\n';
            return 0;
        }
        
        if(mp[{a,cur_b}] == 0){
            q.push({a,cur_b});
            mp[{a,cur_b}] = mp[{cur_a,cur_b}] + 1;
        }

        if(mp[{cur_a,b}] == 0){
            q.push({cur_a,b});
            mp[{cur_a,b}] = mp[{cur_a,cur_b}] + 1;
        }
        
        if(mp[{cur_a,0}] == 0){
            q.push({cur_a,0});
            mp[{cur_a,0}] = mp[{cur_a,cur_b}] + 1;
        }

        if(mp[{0,cur_b}] == 0){
            q.push({0,cur_b});
            mp[{0,cur_b}] = mp[{cur_a,cur_b}] + 1;
        }


        if((cur_a + cur_b <= b) && mp[{0,cur_a+cur_b}] == 0){
            q.push({0,cur_a + cur_b});
            mp[{0,cur_a+cur_b}] = mp[{cur_a,cur_b}] + 1;
        }

        else if((cur_a + cur_b > b) && mp[{cur_a +cur_b - b,b}] == 0){
            q.push({cur_a + cur_b - b,b});
            mp[{cur_a+cur_b - b,b}] = mp[{cur_a,cur_b}] + 1;
        }

        if((cur_a + cur_b <= a) && mp[{cur_a+cur_b,0}] == 0){
            q.push({cur_a+cur_b,0});
            mp[{cur_a+cur_b,0}] = mp[{cur_a,cur_b}] + 1;
        }

        else if((cur_b + cur_a > a) && mp[{a,cur_a +cur_b - a}] == 0){
            q.push({a,cur_a +cur_b - a});
            mp[{a,cur_a +cur_b - a}] = mp[{cur_a,cur_b}] + 1;
        }
    }
    cout << -1 << '\n';
    return 0;
}