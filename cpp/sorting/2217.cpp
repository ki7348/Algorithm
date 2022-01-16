#include <iostream>
#include <algorithm>
#include <vector>

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
    int temp = v[0]*n;
    for(int i=1;i<n;i++){
        if(v[i]*(n-i)>temp){
            temp = v[i]*(n-i);
        }
    }
    cout << temp << '\n';
}