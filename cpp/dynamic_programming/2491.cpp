#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> v;
int going_up[100001];
int going_down[100001];

int main(){
    cin >> n;
    v.push_back(0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    fill(going_up,going_up+100000,1);
    fill(going_down,going_down+100000,1);
    for(int i=2;i<=n;i++){
        if(v[i]>=v[i-1]){
            going_up[i] = going_up[i-1] + 1;
        }
    }
    for(int i=2;i<=n;i++){
        if(v[i]<=v[i-1]){
            going_down[i] = going_down[i-1] + 1;
        }
    }
    int max_val = 0;
    for(int i=1;i<=n;i++){
        max_val = max(max_val,going_up[i]);
    }
    for(int i=1;i<=n;i++){
        max_val = max(max_val,going_down[i]);
    }
    cout << max_val << '\n';
}