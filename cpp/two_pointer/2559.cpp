#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,k;
vector<int> v;

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x; 
        cin >> x;
        v.push_back(x);
    }
    if(k==1){
        cout << *max_element(v.begin(),v.end()) << '\n';
    }
    else{
        int start = 0, end = 0, intervalSum = v[0], result = -100000000;
        while(start<=end && end<n-1){
            while(end-start < k-1){
                end++;
                intervalSum+=v[end];
            }
            result = max(result,intervalSum);
            intervalSum-=v[start];
            start++;
        }
        cout << result << '\n';
    }
}