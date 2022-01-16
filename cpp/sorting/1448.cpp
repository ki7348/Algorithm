#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int result = 0;
    while(v.size()>2){
        int a = v.back();
        v.pop_back();
        int b = v.back();
        v.pop_back();
        int c = v.back();
        if(b+c>a){
            result = b+c+a;
            break;
        }else{
            v.push_back(b);
        }
    }
    if(result==0){
        cout << -1 << '\n';
    }else{
        cout << result << '\n';
    }
}