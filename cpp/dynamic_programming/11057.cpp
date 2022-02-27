#include <iostream>
#include <algorithm>

using namespace std;

int n;
int d[1001][10];

int main(){
    cin >> n;
    for(int i=0;i<10;i++){
        d[1][i] = 1;
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<=j;k++){
                d[i][j] += d[i-1][k];
            }
            d[i][j] %= 10007;
        }
    }
    int result = 0;
    for(int i=0;i<10;i++){
        result += d[n][i];
    }
    cout << result % 10007 << '\n';
}