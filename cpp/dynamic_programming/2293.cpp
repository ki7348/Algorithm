#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, k;
vector<int> v;
int d[10001];

int main() {
    cin >> n >> k;
    v.push_back(0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    d[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=v[i];j<=k;j++){
            d[j] = d[j] + d[j-v[i]];
        }
    }
    cout << d[k] << '\n';
}