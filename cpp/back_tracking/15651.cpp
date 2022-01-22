#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> v;

void dfs(int index){
    if(index == m){
        for(int i=0;i<m;i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1;i<=n;i++){
        v.push_back(i);
        dfs(index+1);
        v.pop_back();
    }
    
}

int main(){
    cin >> n >> m;
    
    dfs(0);

}