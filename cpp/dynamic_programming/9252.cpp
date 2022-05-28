#include <iostream>
#include <algorithm>

using namespace std;
string str1, str2;
int d[1001][1001];

int main() {
    cin >> str1 >> str2;
    for(int i=1;i<=str1.length();i++){
        for(int j=1;j<=str2.length();j++){
            if(str1[i-1] == str2[j-1]){
                d[i][j] = d[i-1][j-1] + 1;
            }else{
                d[i][j] = max(d[i][j-1],d[i-1][j]);
            }
        }
    }

    int x_cur = str1.length()-1;
    int y_cur = str2.length()-1;
    string result = "";
    while(x_cur>=0 && y_cur>=0){
        if(str1[x_cur] == str2[y_cur]) {
            result = str1[x_cur] + result;
            x_cur -= 1;
            y_cur -= 1;
        }
        else{
            if(d[x_cur][y_cur+1] >= d[x_cur+1][y_cur]){
                x_cur -= 1;
            }else{
                y_cur -= 1;
            }
        }
    }

    cout << d[str1.length()][str2.length()] << '\n';

    // for(int i=1;i<=str1.length();i++){
    //     for(int j=1;j<=str2.length();j++){
    //         cout << d[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    if(d[str1.length()][str2.length()] == 0) {
        return 0;
    }
    cout << result << '\n';
}