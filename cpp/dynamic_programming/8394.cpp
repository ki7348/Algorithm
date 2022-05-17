#include <iostream>
#include <algorithm>

using namespace std;
int n;
int d[10000001];

int main() {
    cin >> n;
    d[1] = 1;
    d[2] = 2;
    for(int i=3;i<=10000000;i++){
        if(d[i-1] + d[i-2] > 10000000) {
            d[i-1] %= 10000000;
            d[i-2] %= 10000000;
        }
        d[i] = d[i-1] + d[i-2];
    }
    cout << to_string(d[n]).back()  << '\n';
}