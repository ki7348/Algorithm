#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
string str1, str2, str3;
int d[101][101][101];
int result = 0;

int main() {
    cin >> str1 >> str2 >> str3;
    for(int i=1;i<=str1.length();i++){
        for(int j=1;j<=str2.length();j++){
            for(int k=1;k<=str3.length();k++){
                if(str1[i-1] == str2[j-1] && str2[j-1] == str3[k-1]){
                    d[i][j][k] = d[i-1][j-1][k-1] + 1;
                }else{
                    d[i][j][k] = max(d[i][j][k-1],d[i][j-1][k]);
                    d[i][j][k] = max(d[i][j][k],d[i-1][j][k]);
                }
                result = max(result,d[i][j][k]);
            }
        }
    }
    cout << result << '\n';
}