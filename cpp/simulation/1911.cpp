#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
    
    int n;
    int l;
    cin >> n >> l;
    vector<pair<int,int>> v;

    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());

    int answer = 0;
    int next = 0;
    for(int i=0;i<n;i++){
        if(next < v[i].first){
            next = v[i].first;
        }

        while(next < v[i].second){
            next += l;
            answer++;
        }
    }

    cout << answer << '\n';


}