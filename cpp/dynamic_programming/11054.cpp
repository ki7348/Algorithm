#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> v;
int right_val[1001];
int left_val[1001];

int main() {
    cin >> n;
    v.push_back(0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    fill(left_val,left_val+1001,1);
    fill(right_val,right_val+1001,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(v[i] > v[j]){
                left_val[i] = max(left_val[i],left_val[j] + 1);
            }
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=n;j>i;j--){
            if(v[i] > v[j]){
                right_val[i] = max(right_val[i],right_val[j] + 1);
            }
        }
    }
    int result = 0;
    for(int i=1;i<=n;i++){
        result = max(result,left_val[i]+right_val[i]);
    }
    cout << result -1 << '\n';
    
}