#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
long long d[91];

int main(){
    cin >> n;
    d[1] = 1;
    d[2] = 1;
    for(int i=3;i<=n;i++){
        d[i]=d[i-1] + d[i-2];
    }
    cout << d[n] << '\n';
}