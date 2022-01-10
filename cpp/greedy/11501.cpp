#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;

    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        vector<int> v;
        long result = 0;
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        int temp = -1;
        for(int j=n-1;j>=0;j--){
            temp = max(temp,v[j]);
            result+=temp-v[j];
        }
        cout << result << '\n';
    }
}