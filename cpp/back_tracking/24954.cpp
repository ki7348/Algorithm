#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
vector<int> v;
int n;
vector<pair<int,int>> graph[11];
bool visited[11];
vector<int> temp;
int result = 1e9;

void back_tracking(int index){
    if(index == n){
        vector<int> temp_v =  v;
        int sum_val = 0;
        for(int i=0;i<n;i++){
            sum_val+=temp_v[temp[i]];
            for(int j=0;j<graph[temp[i]].size();j++){
                int target = graph[temp[i]][j].first;
                int val = graph[temp[i]][j].second;
                temp_v[target] = max(1,temp_v[target] - val);
            }
        }
        // for(int i=0;i<n;i++){
        //     cout << temp_v[i] << ' ';
        // }
        // cout << '\n';
        result = min(result,sum_val);
        return;
    }
    for(int i=0;i<n;i++){
        if(visited[i]){
            continue;
        }
        visited[i] = true;
        temp.push_back(i);
        back_tracking(index+1);
        temp.pop_back();
        visited[i] = false;
    }
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        for(int j=0;j<x;j++){
            int a,b;
            cin >> a >> b;
            graph[i].push_back({a-1,b});
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<graph[i].size();j++){
    //         cout <<graph[i][j].first << ' ' << graph[i][j].second << '\n';
    //     }
    // }
    back_tracking(0);
    cout << result << '\n';
}