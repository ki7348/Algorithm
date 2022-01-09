#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    map<string,string> first;
    map<string,vector<string>> second;

    for(int i=0;i<n;i++){
        vector<string> temp;
        string group;
        cin >> group;
        int member;
        cin >> member;
        for(int j=0;j<member;j++){
            string girl;
            cin >> girl;
            first[girl] = group;
            temp.push_back(girl);
        }
        sort(temp.begin(),temp.end());
        second[group] = temp;
    }
    for(int i=0;i<m;i++){
        string quiz;
        cin >> quiz;
        int select;
        cin >> select;
        if(select==1){
            cout << first[quiz] << '\n';
        }else{
            for(int j=0;j<second[quiz].size();j++)
            cout << second[quiz][j] << '\n';
        }
    }
}