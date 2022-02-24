#include<iostream>
#include<vector>

using namespace std;

int n,m;
vector<int> v;

int main(){
    cin >> n >> m;
    int cnt = 0, intervalSum = 0, end = 0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int start = 0; start < n; start++){
        while(intervalSum < m && end < n){
            intervalSum += v[end];
            end+=1;
        }
        if(intervalSum == m){
            cnt += 1;
        }
        intervalSum -= v[start];
    }
    cout << cnt << '\n';
}

