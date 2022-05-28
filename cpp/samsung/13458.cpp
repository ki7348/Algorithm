// Math

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int n;
long long first, second;

int main() {
    cin >> n;
    vector<long long> v;
    for(int i=0;i<n;i++) { 
        int x;
        cin >> x;
        v.push_back(x);
    }
    cin >> first >> second;
    for(int i=0;i<v.size();i++) {
        if(v[i] - first >= 0) {
            v[i] -= first;
        } else {
            v[i] = 0;
        }
    }
    long long result = 0;
    for(int i=0;i<v.size();i++) {
        result += ceil((double)v[i] / (double)second);
    }
    cout << result + n << '\n';
}