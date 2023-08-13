#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;

    map<int,int> mp;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        mp[i] = x;
    }

    int idx = 0;


    int count = 0;

    while(n--){
        if(idx == k){
            cout << count << '\n';
            return 0;
        }
        idx = mp[idx];
        count++;
    }

    cout << -1 << '\n';
}