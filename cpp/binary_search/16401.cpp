#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<long long> v;

    for(int i=0;i<m;i++){
        long long x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());

    long long start = 1;
    int answer = 0;
    long long end = v.back();

    while(start <= end){
        long long mid = (start + end) / 2;
        long long total = 0;
        for(int i=0;i<v.size();i++){
            total += v[i] / mid;
        }

        if(total >= n){
            start = mid + 1;
            answer = mid;
        }else{
            end = mid - 1;
        }
    }

    cout << answer << '\n';
}