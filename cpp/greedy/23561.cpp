#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<3*n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());

    vector<int> selected;
    for(int i=0;i<n;i++){
        selected.push_back(v[n+i]);
    }

    cout <<selected.back() - selected.front() << '\n';
}