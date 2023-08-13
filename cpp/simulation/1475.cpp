#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
 
using namespace std;

int main(){
    int n;
    cin >> n;

    string str;
    str = to_string(n);

    map<int,int> mp;

    for(int i=0;i<str.length();i++){
        mp[str[i] - '0']+=1;
    }

    int answer = 0;

    for(int i=0;i<=9;i++){
        if(i == 6 || i == 9){
            continue;
        }
        answer = max(answer,mp[i]);
    }

    int sixandnine = 0;

    sixandnine = int(ceil((mp[6]+mp[9]) / 2.0));

    
    cout << max(answer,sixandnine) << '\n';
}