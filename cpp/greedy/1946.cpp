#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            v.push_back({a,b});

        }
        sort(v.begin(),v.end());
        int answer = 1;
        int min_val = v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].second < min_val){
                answer++;
                min_val = v[i].second;
            }
        }

        cout << answer << '\n';
    }
}