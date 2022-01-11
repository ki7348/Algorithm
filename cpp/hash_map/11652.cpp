#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    map<long long, int> m;
    map<long long, int>::iterator iter;
    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        m[x] += 1;
    }
    int max_elem = m.begin()->second;
    long long max_index = m.begin()->first;
    for(iter=m.begin();iter!=m.end();iter++){
        if(iter->second>max_elem){
            max_elem = iter->second;
            max_index = iter->first;
        }
    }
    cout << max_index << '\n';
}