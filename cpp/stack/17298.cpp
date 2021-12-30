#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int x;
    cin >> x;

    stack<int> s;
    vector<int> v;
    int result[1000001];

    for(int i=0;i<x;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    for(int i=x-1;i>=0;i--){
        while(!s.empty()&&s.top()<=v[i]){
            s.pop();
        }
        if(s.empty()){
            result[i] = -1;
        }else{
            result[i] = s.top();
        }
        s.push(v[i]);
    }
    for(int i=0;i<x;i++){
        cout << result[i] << " ";
    }
}