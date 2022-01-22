#include <iostream>
#include <vector>

using namespace std;

int n,m;
bool check[9];
vector<int> v;

void dfs(int index){
    if(index == m){
        for(int i=0;i<m;i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
    for(int i=1;i<=n;i++){
        if(check[i])
            continue;
        check[i] = true;
        v.push_back(i);
        dfs(index+1);
        v.pop_back();
        check[i] = false;
    }
    
}

int main(){
    cin >> n >> m;
    
    dfs(0);

}