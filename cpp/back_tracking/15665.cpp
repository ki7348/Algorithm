#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
vector<int> result;

void back_tracking(int index){
    int temp = 0;
    if(index==m){
        for(int i=0;i<result.size();i++)
            cout << v[result[i]] << ' ';
        cout << '\n';
        return;
    }
    for(int i=1;i<n+1;i++){
        if(temp==v[i])
            continue;
        result.push_back(i);
        temp = v[i];
        back_tracking(index+1);
        result.pop_back();
    }
}

int main(){
    cin >> n >> m;
    v.push_back(0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    back_tracking(0);
}