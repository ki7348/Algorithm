#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int m;
vector<int> v;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    cin >> m;
    sort(v.begin(),v.end());
    int cnt = 0, duoSum = 0, end = n-1;
    int start = 0;
    while(start<end){
        if(v[start]+v[end] == m){
            cnt++;
            end-=1;
        }
        else if(v[start]+v[end]>m){
            end-=1;
        }else{
            start+=1;
        }
    }
    cout << cnt << '\n';
}