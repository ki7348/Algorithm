#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int> v;

void dfs(int index,vector<int> input, int idx){
    if(index == m){
        for(int i=0;i<m;i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=idx;i<=n;i++){
        v.push_back(input[i]);
        dfs(index+1,input,i);
        v.pop_back();
    }
    
}

int main(){
    cin >> n >> m;
    vector<int> input;
    input.push_back(0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        input.push_back(x);
    }
    sort(input.begin(),input.end());
    
    dfs(0,input,1);

}