#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int n,k;
int result = 0;
vector<int> attack;
vector<int> people;
vector<int> temp;
map<vector<int>,bool> mp;

bool check[21];

void back_tracking(int index){
    int life = k;
    int tired = 0;
    int save = 0;
    for(int i=0;i<temp.size();i++){
        if(life - (tired + attack[temp[i]]) < 0){
            mp[temp] += 1;
            break;
        }
        life -= tired;
        life -= attack[temp[i]];
        save += people[temp[i]];
        tired += attack[temp[i]];
    }
    result = max(result,save);
    for(int i=0;i<n;i++){
        if(check[i]){
            continue;
        }
        if(mp[temp] >0 ){
            continue;
        }
        check[i] = true;
        temp.push_back(i);
        back_tracking(index+1);
        check[i] = false;
        temp.pop_back();
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        attack.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        people.push_back(x);
    }

    back_tracking(1);
    cout << result << '\n';
}