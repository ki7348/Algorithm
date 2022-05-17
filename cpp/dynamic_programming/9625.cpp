#include <iostream>
#include <algorithm>

using namespace std;
int k;
long long d[50];

int main(){
    cin >> k;
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    d[3] = 3;
    d[4] = 5;
    for(int i=5;i<50;i++){
        d[i] = d[i-1] + d[i-2];
    }
    if(k==1) {
        cout << 0 << ' ' << 1 << '\n';
        return 0;
    }
    cout << d[k-2] << ' ' << d[k-1] << '\n';
}