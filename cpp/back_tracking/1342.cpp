#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string str;
vector<char> start;
vector<char> v;
int total = 0;
bool check[10];

void back_tracking(int index){
    if(index==start.size()){
        int x = 0;
        for(int i=0;i<v.size()-1;i++){
            if(start[v[i]]!=start[v[i+1]])
                x++;
        }
        if(x == start.size()-1)
            total++;
        return;
        // for(int i=0;i<v.size();i++){
        //     cout << start[v[i]] << ' ';
        // }
        // cout << '\n';
        // return;
    }
    int temp = 0;
    for(int i=0;i<start.size();i++){
        if(check[i] || temp==start[i])
            continue;
        check[i] = true;
        v.push_back(i);
        temp = start[i];
        back_tracking(index+1);
        v.pop_back();
        check[i] = false;
    }
}

int main(){
    cin >> str;
    for(int i=0;i<str.length();i++)
        start.push_back(str[i]);
    sort(start.begin(),start.end());
    back_tracking(0);
    cout << total <<'\n';
}