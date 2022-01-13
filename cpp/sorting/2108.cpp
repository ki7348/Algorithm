#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    map<int,int> m;
    map<int,int>::iterator iter;
    
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
        m[x] += 1;
    }
    sort(v.begin(),v.end());
    double sum = accumulate(v.begin(),v.end(),0);
    cout << round(sum/n) << '\n';
    cout << v[floor(n/2)] << '\n';

    vector<pair<int,int>> temp(m.begin(),m.end());
    sort(temp.begin(),temp.end(),compare);

    // for(int i=0;i<temp.size();i++){
    //     cout << temp[i].first << ' ' << temp[i].second << '\n';
    // }

    if(temp.size()==1){
        cout << temp[0].first << '\n';
    }else if(temp.size()>1 && temp[0].second==temp[1].second){
        cout << temp[1].first << '\n';
    }else if(temp.size()>1 && temp[0].second!=temp[1].second){
        cout << temp[0].first << '\n';
    }
    cout << v.back() - v.front() << '\n';
}