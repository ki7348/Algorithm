#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;

int d[12];

int main(){
    cin >> t;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i=4;i<12;i++){
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }
    for(int i=0;i<t;i++){
        int x;
        cin >> x;
        cout << d[x] << '\n';
    }
}