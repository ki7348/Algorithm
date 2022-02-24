#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> v;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int start = 0, end = n - 1, result = 2000000001;
    vector<int> temp_v;
    while(start<end){
        int temp = v[start] + v[end];
        if(abs(temp)<=result){
            result = abs(temp);
            temp_v.clear();
            temp_v.push_back(v[start]);
            temp_v.push_back(v[end]);
        }
        if(temp>0){
            end--;
        }else{
            start++;
        }
    }
    cout << temp_v[0] << ' ' << temp_v[1] << '\n';
}