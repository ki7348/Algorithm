#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> v;

void dfs(int index,int idx){
    if(index == m){
        for(int i=0;i<m;i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=idx;i<=n;i++){
        v.push_back(i);
        dfs(index+1,i);
        v.pop_back();
    }
    
}

int main(){
    cin >> n >> m;
    
    dfs(0,1);

}