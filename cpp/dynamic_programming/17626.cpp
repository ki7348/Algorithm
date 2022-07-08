#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#define INF 1e9

using namespace std;
int n;
int d[50001];

int main() {
    cin >> n;
    fill(d,d+50001,INF);
    d[0] = 0;
    d[1] = 1;
    d[2] = 2;
    d[3] = 3;
    d[4] = 1;
    for(int i=5;i<=n;i++){
        if(floor(sqrt(i)) == sqrt(i)){
            d[i] = 1;
            continue;
        }
        for(int j=1 ;j <= floor(sqrt(i)); j++){
            d[i] = min(d[i],1 + d[i-j*j]);
        }
    }
    cout << d[n] << '\n';
}