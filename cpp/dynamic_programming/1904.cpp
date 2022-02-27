#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int d[1000001];

int main(){
    cin >> n;
    d[1] = 1;
    d[2] = 2;
    for(int i=3;i<=n;i++){
        d[i] = (d[i-1] + d[i-2]) % 15746;
    }
    cout << d[n] << '\n';
}