#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    long long s;
    cin >> s;
    long long sum = 0;
    if(s == 2){
        cout << 1 << '\n';
        return 0;
    }
    if(s == 3){
        cout << 2 << '\n';
        return 0;
    }
    for(int i=1;i<=s;i++){
        sum += i;
        if (sum == s){
            cout << i << '\n';
            break;
        }
        if (sum > s){
            cout << i-1 << '\n';
            break;
        }
    }
}