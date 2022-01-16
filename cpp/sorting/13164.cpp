#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<long long> v;
    priority_queue<long long> diff;

    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());

    for(int i=0;i<v.size()-1;i++){
        diff.push(v[i+1]-v[i]);
    }
    for(int i=0;i<k-1;i++){
        diff.pop();
    }
    long long result = 0;
    while(!diff.empty()){
        result+=diff.top();
        diff.pop();
    }
    cout << result << '\n';

}