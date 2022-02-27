#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int t;
long long d[65][11];

int main(){
    cin >> t;
    for(int i=1;i<=10;i++){
        d[1][i] = 1;
    }
    for(int i=1;i<=10;i++){
        d[2][i] = i;
    }
    for(int i=3;i<65;i++){
        long long temp = 0;
        for(int j=1;j<=10;j++){
            temp+=d[i-1][j];
        }
        d[i][10] = temp;
        for(int j=9;j>=1;j--){
            d[i][j] = d[i][j+1] - d[i-1][j+1];
        }   
    }
    for(int i=0;i<t;i++){
        int x;
        cin >> x;
        long long result = 0;
        for(int i=1;i<=10;i++)
            result+=d[x][i];
        cout << result << '\n';
    }
}