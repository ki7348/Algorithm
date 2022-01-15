#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    if(v.size()%2==1){
    cout << v[v.size()/2] << '\n';
    }else{
        cout << v[v.size()/2-1] << '\n';
    }
}