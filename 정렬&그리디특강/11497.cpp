#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;
int t;

int main(){
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        deque<int> dq;
        for(int i=n-1;i>=0;i--){
            if(i%2 == 0){
                dq.push_back(v[i]);
            }else{
                dq.push_front(v[i]);
            }
        }
        int result = abs(dq.front() - dq.back());
        for(int i=0;i<n-1;i++){
            result = max(result,abs(dq[i]-dq[i+1]));
        }
        cout << result << '\n';
    }
}