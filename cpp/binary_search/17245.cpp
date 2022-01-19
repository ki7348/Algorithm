#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    long long end = 0;
    vector<vector<long long>> v;
    long long sum = 0;
    for(int i=0;i<n;i++){
        vector<long long> v2;
        for(int j=0;j<n;j++){
            long long x;
            cin >> x;
            sum+=x;
            v2.push_back(x);
            if(x>end){
                end = x;
            }
        }
        v.push_back(v2);
    }
    long long start = 0;
    long long result;
    long long middle_point = round((double)sum/2);
    while(start<=end){
        long long mid = (start+end) / 2;
        long long total = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]>=mid){
                    total += mid;
                }else{
                    total += v[i][j];
                }
            }
        }
        if (total >= middle_point){
                end = mid - 1;
                result = mid;
            }
        else{
            start = mid + 1;
        }
    }
    cout << result << '\n';
}