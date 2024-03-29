#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> v;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        v.push_back(x);
    }

    long long start = 1;
    long long end = *max_element(v.begin(),v.end());

    while(start <= end){
        long long mid = (start + end) / 2;

        int cnt = 0;
        for(int i=0;i<v.size();i++){
            if(v[i] == 0){
                continue;
            }
            cnt += v[i] / mid;
        }

        if(cnt >= k){
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << start - 1 << '\n';
}