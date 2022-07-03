#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> v;
int diff[100001];

int main() {
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        diff[i] = diff[i-1] + x;
    }
    int result = -1e9;
    for(int i=k;i<=n;i++){
        result = max(result,diff[i] - diff[i-k]);
    }
    cout << result << '\n';
}