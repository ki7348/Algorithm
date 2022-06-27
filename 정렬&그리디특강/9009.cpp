#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<long long> v;
    int first = 1;
    int second = 1;
    int n = 1;
    v.push_back(1);
    while(n<=1000000000){
        n = first + second;
        v.push_back(n);
        int temp = second;
        second = n;
        first = temp;
    }
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        int remain = x;
        int idx = v.size() - 1;
        vector<int> result;
        while(remain > 0){
            while(v[idx] > remain){
                idx--;
            }
            remain -= v[idx];
            result.push_back(v[idx]);
        }
        for(int i=result.size()-1;i>=0;i--){
            cout << result[i] << ' ';
        }
        cout << '\n';
    }
}