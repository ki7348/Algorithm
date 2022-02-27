#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<int> v;
int d[1001];

int main(){
    cin >> n;
    v.push_back(0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i=1;i<=n;i++){
        d[i] = v[i];
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            d[i] = max(d[i],d[i-j]+v[j]);
        }
    }
    cout << d[n] << '\n';
}