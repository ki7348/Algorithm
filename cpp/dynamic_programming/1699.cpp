#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n;
int d[100001] = {};

int main(){
    cin >> n;
    for(int i=0;i<100001;i++){
        d[i] = 100000;
    }
    d[1] = 1;
    d[2] = 2;

    for(int i=3;i<=n;i++){
        if(sqrt(i)-floor(sqrt(i))==0){
            d[i] = 1;
        }else{
            for(int j=1;j<=floor(sqrt(i));j++){
                d[i] = min(d[i],d[i-(int)pow(j,2)] + 1);
            }
        }
    }
    cout << d[n] << '\n';
}