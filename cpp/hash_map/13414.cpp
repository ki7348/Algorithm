#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, int>a, pair<string, int>b) {
	return a.second < b.second;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int k,l;
    cin >> k >> l;
    unordered_map<string,int> m;

    for(int i=0;i<l;i++){
        string str;
        cin >> str;
        m[str] = i+1;
    }
    int min_num = 0;
    vector<pair<string,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<k;i++){
        if(i<v.size()){
            cout << v[i].first <<  '\n';
        }else{
            continue;
        }
    }
    return 0;
}