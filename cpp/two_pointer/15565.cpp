#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int k,n;
    cin >> k >> n;
    vector<int> v;

    vector<int> idx;

    for(int i=0;i<k;i++){
        int x;
        cin >> x;
        v.push_back(x);
        if(x == 1){
            idx.push_back(i);
        }
    }

    if(idx.size() < n){
        cout << -1 << '\n';
        return 0;
    }

    int result = 9999999;
    for(int i=0;i<idx.size()-n+1;i++){
        result = min(result, idx[i+n-1] - idx[i] + 1);
    }

    cout << result << '\n';
}