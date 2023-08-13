#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> v;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    long long t;

    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        v.push_back(x);
    }

    long long start = *min_element(v.begin(),v.end());
    long long end = *max_element(v.begin(),v.end());

    while(start <= end){
        long long mid = (start + end) / 2;
        long long aid = 0;
        for(int i=0;i<v.size();i++){
            if(v[i] < mid){
                aid += mid - v[i];
            }
        }

        if(aid >= k){
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        cout << start << ' ' << end << '\n';
    }
}