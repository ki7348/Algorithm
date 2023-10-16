#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int d[100001];

    int n;
    cin >> n;

    d[1] = 1;
    d[2] = 1;
    d[3] = 2;
    d[4] = 2;
    d[5] = 1;
    d[6] = 2;
    d[7] = 1;
    for(int i=8;i<=n;i++){
        if(i % 7 == 0){
            d[i] = i / 7;
            continue;
        }
        d[i] = min({d[i-7],d[i-5],d[i-2],d[i-1]}) + 1;
    }

    cout << d[n] << '\n';
}