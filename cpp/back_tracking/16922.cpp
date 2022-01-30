#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int n;
vector<int> v;
vector<int> result;
int k = 0;
bool check[1001];

void back_tracking(int index){
    if(index==n){
        int temp = accumulate(result.begin(),result.end(),0);
        if(check[temp])
        return;
        check[temp] = true; 
        k++;
        return;
    }
    for(int i=0;i<v.size();i++){
        result.push_back(v[i]);
        back_tracking(index+1);
        result.pop_back();
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    v.push_back(1);
    v.push_back(5);
    v.push_back(10);
    v.push_back(50);
    back_tracking(0);
    cout << k << '\n';
}