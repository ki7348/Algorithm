#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<int> v;
bool check[9];
vector<int> result;
vector<int> final;
int ans = 0;

void back_tracking(int index){
    if(index==n){
        int temp = 0;
        for(int i=1;i<n;i++){
            temp += abs(v[result[i]]-v[result[i-1]]);
        }
        ans=max(temp,ans);
        return;
    }
    for(int i=0;i<n;i++){
        if(check[i])
            continue;
        check[i] = true;
        result.push_back(i);
        back_tracking(index+1);
        result.pop_back();
        check[i] = false;
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    back_tracking(0);
    cout << ans << '\n';
}