#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());

    int time = 0;
    for(int i=0;i<m;i++){
        
    }
}