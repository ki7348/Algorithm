#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,k;
vector<int> v;
int check[100001];

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int start = 0, end = 0, len = 0;

    while(start<=end && end<n){
        if(check[v[end]]<k){
            check[v[end++]]++;
            len = max(len,end-start);
        }else{
            while(check[v[end]]>=k){
                check[v[start++]]-=1;
            }
        }
    }
    cout << len << '\n';
}