#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<string> v;
vector<string> asce;
vector<string> desc;

bool compare (string str1, string str2){
    return str1 > str2;
}

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        v.push_back(str);
        asce.push_back(str);
        desc.push_back(str);
    }
    sort(asce.begin(),asce.end());
    sort(desc.begin(),desc.end(),compare);
    int asce_num = 0;
    for(int i=0;i<v.size();i++){
        if(v[i] == asce[i]){
            asce_num++;
        }
    }
    if(asce_num == n){
        cout << "INCREASING" << '\n';
        return 0;
    }
    int desc_num = 0;
    for(int i=0;i<v.size();i++){
        if(v[i] == desc[i]){
            desc_num++;
        }
    }
    if(desc_num == n){
        cout << "DECREASING" << '\n';
        return 0;
    }
    cout << "NEITHER" << '\n';
    return 0;
}