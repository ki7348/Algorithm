#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());
    long long total = 0;
    for(int i=0;i<v.size();i++){
        total += abs(v[i] - (i+1));
    }

    cout << total << '\n';
}