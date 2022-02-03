#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v;
int d[1000] = {};

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i=0;i<1000;i++){
        d[i] = 1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[i] > v[j]){
                d[i] = max(d[i],d[j]+1);
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     cout << d[i] << ' ';
    // }
    // cout << '\n';
    int result = 0;
    for(int i=0;i<n;i++){
        result=max(result,d[i]);
    }
    cout << result << '\n';
}