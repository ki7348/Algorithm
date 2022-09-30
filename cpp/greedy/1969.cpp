#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,m;
vector<string> v;

bool compare(pair<char,int> p1, pair<char,int> p2){
    if(p1.second != p2.second){
        return p1.second > p2.second;
    }
    return p1.first < p2.first;
}


int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        v.push_back(str);
    }
    string result = "";
    for(int i=0;i<m;i++){
        vector<pair<char,int>> temp;
        for(int j=0;j<n;j++){
            int findIdx = 0;
            bool find = false;
            for(int k=0;k<temp.size();k++){
                if(temp[k].first == v[j][i]){
                    find = true;
                    findIdx = k;
                    break;
                }
            }
            if(find){
                temp[findIdx].second++;
            }else{
                temp.push_back({v[j][i],1});
            }
        }   
        sort(temp.begin(),temp.end(),compare);
        result += temp.front().first;
    }

    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<result.length();j++){
            if(result[j] != v[i][j]){
                cnt++;
            }
        }
    }

    cout << result << '\n';
    cout << cnt << '\n';
}