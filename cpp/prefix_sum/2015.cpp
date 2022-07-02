#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
vector<int> v;
int prefix_sum[200001];
map<int,long long> MAP;

int main() {
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    prefix_sum[0] = v[0];
    for(int i=1;i<n;i++){
        prefix_sum[i] = prefix_sum[i-1] + v[i];
    }
    long long result = 0;
    for(int i=0;i<n;i++){
        if(prefix_sum[i] == k){
            result++;
        }
        result += MAP[prefix_sum[i] - k];
        MAP[prefix_sum[i]]++;
    }
    cout << result << '\n';
}