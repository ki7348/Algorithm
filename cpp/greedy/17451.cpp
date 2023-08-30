#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<long long> v;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    double start = v[n-1];
    for(int i=n-2;i>=0;i--){
        if(v[i] > start){
            start = v[i];
        }else{
            start = v[i] * ceil(start / v[i]);
        }
    }
    cout << (long long)start << '\n';
}