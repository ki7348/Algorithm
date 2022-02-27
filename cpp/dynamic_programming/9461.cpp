#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int t;
long long d[101];

int main(){
    cin >> t;
    d[1] = 1;
    d[2] = 1;
    d[3] = 1;
    d[4] = 2;
    for(int i=5;i<=100;i++)
        d[i] = d[i-2] + d[i-3];
    for(int i=0;i<t;i++){
        int x;
        cin >> x;
        cout << d[x] << '\n';
    }
}