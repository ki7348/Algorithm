#include <iostream>
#include <algorithm>
#include <vector>

struct Conf {
    int start;
    int end;
    int value;
};

using namespace std;

bool compare(Conf a, Conf b){
    return a.start < b.start;
}

int main(){
    int n;
    cin >> n;
    vector<Conf> v;

    for(int i=0;i<n;i++){
        int x,y,z;
        cin >> x >> y >> z;
        v.push_back({x,y,z});
    }

    sort(v.begin(),v.end(),compare);

    int dp[26];

    for(int i=0;i<n;i++){
        dp[i] = v[i].value;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[j].end < v[i].start){
                dp[i] = max(dp[i],dp[j] + v[i].value);
            }
        }
    }

    int answer = dp[0];
    for(int i=0;i<n;i++){
        answer = max(answer,dp[i]);
    }

    cout << answer << '\n';
}