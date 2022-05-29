#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int d[1000001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    int result = 0;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        d[x] = d[x-1] + 1;
        result = max(result,d[x]);
    }
    cout << n - result << '\n';
    
}