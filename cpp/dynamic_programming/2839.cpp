#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int d[5001];

int main() {
    cin >> n;
    d[3] = 1;
    d[5] = 1;
    for(int i=6;i<=n;i++){
        if(d[i-3]){
            d[i] = d[i-3]+1;
        }
        if(d[i-5]){
            d[i] = d[i] ? min(d[i] , d[i - 5] + 1) : d[i - 5] + 1;
        }
    }
    cout << (d[n] == 0 ? -1 : d[n]) << '\n';
}