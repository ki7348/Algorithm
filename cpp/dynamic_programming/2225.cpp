#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,k;
unsigned long long d[201][201];

int main(){
    cin >> n >> k;
    for(int i=0;i<201;i++){
        d[i][1] = 1;
    }
    for(int i=0;i<201;i++){
        d[0][i] = 1;
    }
    for(int i=2;i<201;i++) {
        for(int j=1;j<201;j++) {
            d[j][i] = (d[j-1][i] + d[j][i-1]) % 1000000000;
        }
    }
    cout << d[n][k] << '\n';

}
