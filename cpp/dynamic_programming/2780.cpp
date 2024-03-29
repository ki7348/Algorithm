#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    long long d[1001][10];
    d[1][0] = 1;
    d[1][1] = 1;
    d[1][2] = 1;
    d[1][3] = 1;
    d[1][4] = 1;
    d[1][5] = 1;
    d[1][6] = 1;
    d[1][7] = 1;
    d[1][8] = 1;
    d[1][9] = 1;

    for(int i=2;i<1001;i++){
        d[i][0] = (d[i-1][7]) % 1234567;
        d[i][1] = (d[i-1][2] + d[i-1][4]) % 1234567;
        d[i][2] = (d[i-1][1] + d[i-1][3] + d[i-1][5]) % 1234567;
        d[i][3] = (d[i-1][2] + d[i-1][6]) % 1234567;
        d[i][4] = (d[i-1][1] + d[i-1][5] + d[i-1][7]) % 1234567;
        d[i][5] = (d[i-1][2] + d[i-1][4] + d[i-1][6] + d[i-1][8]) % 1234567;
        d[i][6] = (d[i-1][3] + d[i-1][5] + d[i-1][9]) % 1234567;
        d[i][7] = (d[i-1][4] + d[i-1][8] + d[i-1][0]) % 1234567;
        d[i][8] = (d[i-1][5] + d[i-1][7] + d[i-1][9]) % 1234567;
        d[i][9] = (d[i-1][6] + d[i-1][8]) % 1234567;
    }

    while(t--){
        int n;
        cin >> n;

        long long answer = 0;
        for(int i=0;i<10;i++){
            answer += d[n][i] % 1234567;
        }

        cout << answer % 1234567 << '\n';
    }
}