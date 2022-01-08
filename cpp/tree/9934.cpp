#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int tree[1024];
vector<int> layer[11];

void make_tree(int k, int l, int left){
    if(k==0){
        return;
    }
    int bias = pow(2,k-1) - 1;
    layer[l].push_back(tree[left+bias]);
    make_tree(k-1,l+1,left);
    make_tree(k-1,l+1,left+bias+1);
}

int main(){

    int k;
    cin >> k;

    for(int i=0;i<pow(2,k)-1;i++){
        cin >> tree[i];
    }

    make_tree(k,1,0);

    for(int i=1;i<=k;i++){
        for(int j=0;j<layer[i].size();j++){
            cout << layer[i][j] << ' ';
        }
        cout << '\n';
    }
}