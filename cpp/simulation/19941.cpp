#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool check[20001];

int main() {
    int n,k;
    cin >> n >> k;
    string str;
    cin >> str;
    int answer = 0;

    for(int i=n-1;i>=0;i--){
        if(str[i] == 'P'){
            for(int j=i+k;j>=i-k;j--){
                if(j >= 0 && j < n && str[j] == 'H'){
                    if(!check[j]){
                        check[j] = true;
                        answer++;
                        break;
                    }
                }
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     cout << check[i] << ' ';
    // }
    // cout << '\n';
    cout << answer << '\n';
}