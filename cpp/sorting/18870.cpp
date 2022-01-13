#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    vector<int> temp;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
        temp.push_back(x);
    }
    sort(temp.begin(),temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    map<int,int> m;
    for(int i=0;i<temp.size();i++){
        m[temp[i]] = i;
    }
    for(int i=0;i<v.size();i++){
        cout << m[v[i]] << ' ';
    }

    
}