#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
bool check[10001];
vector<int> v;

void dfs(int index,vector<int> input){
    if(index == m){
        for(int i=0;i<m;i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(check[input[i]])
            continue;
        check[input[i]] = true;
        v.push_back(input[i]);
        dfs(index+1,input);
        v.pop_back();
        check[input[i]] = false;
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
    
    dfs(0,input);

}