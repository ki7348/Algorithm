#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> lost;
vector<int> gain;
int d[21][100];

int main() {
    cin >> n;
    lost.push_back(0);
    gain.push_back(0);
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        lost.push_back(x);
    }
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        gain.push_back(x);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=99;j++){
            if(lost[i] <= j) {
                d[i][j] = max(d[i-1][j], d[i-1][j-lost[i]] + gain[i]);
            }else{
                d[i][j] = d[i-1][j];
            }
        }
    }
    cout << d[n][99] << '\n';
}