#include <iostream>

using namespace std;
int n;
long long int d[1001];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    d[1] = 1;
    d[2] = 3;
    for(int i=3;i<=n;i++){
        d[i] = (d[i-1] + 2*d[i-2]) % 10007;
    }
    cout << d[n] % 10007 << '\n';
}