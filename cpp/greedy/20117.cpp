#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());

    int answer = 0;
    for(int i=0;i<n/2;i++){
        answer += v[n-i-1] * 2;
    }
    if(n % 2 == 1){
        answer += v[n / 2];
    }

    cout << answer << '\n';
}