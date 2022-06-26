#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;

int main() {
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int x;
    cin >> x;
    int result = 0;
    sort(v.begin(),v.end());
    int start = 0;
    int end = n-1;
    while(start < end){
        if(v[start] + v[end] > x){
            end--;
        }else if(v[start] + v[end] < x){
            start++;
        }else{
            result++;
            start++;
            end--;
        }
    }
    cout << result << '\n';
}