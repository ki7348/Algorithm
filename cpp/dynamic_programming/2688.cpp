#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int t;
long long d[65][11];
long long sum_elem[65];

int main(){
    cin >> t;
    for(int i=1;i<11;i++){
        d[1][i] = 1;
    }
    sum_elem[1] = 10;
    for(int i=1;i<11;i++){
        d[2][i] = i;
    }
    sum_elem[2] = 55;
    for(int i=3;i<65;i++){
        d[i][10] = sum_elem[i-1];
        for(int j=9;j>0;j--){
            d[i][j] = d[i][j+1] - d[i-1][j+1];
        }
        long long temp = 0;
        for(int j=1;j<11;j++){
            temp += d[i][j];
        }
        sum_elem[i] = temp;
    }
    for(int i=0;i<t;i++){
        int x;
        cin >> x;
        cout << sum_elem[x] << '\n';
    }
    
}