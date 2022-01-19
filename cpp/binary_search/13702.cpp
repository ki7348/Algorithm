#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >>  n >> k;
    vector<long long> v;

    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        v.push_back(x);
    }
    long long start = 1;
    long long end = *max_element(v.begin(),v.end());
    long long result = 1;
    while(start<=end){
        long long mid = (start+end) / 2;
        long long total = 0;
        for(int i=0;i<n;i++){
            total += v[i] / mid;
        }
        if (total < k){
                end = mid - 1;
            }
        else{
            start = mid + 1;
            result = mid;
        }
    }
    cout << result << '\n';
    
}


