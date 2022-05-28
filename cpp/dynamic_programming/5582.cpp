#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int d[4001][4001];
string str1;
string str2;

int main(){
    cin >> str1 >> str2;
    int result = 0;
    
    for(int i=1;i<=str1.size();i++){
        for(int j=1;j<=str2.size();j++){
            if(str1[i-1]==str2[j-1])
                d[i][j] = d[i-1][j-1] + 1;
            result = max(result, d[i][j]);
        }
    }
    cout << result << '\n';
    
}