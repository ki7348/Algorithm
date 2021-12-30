#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    stack<pair<int,int>> s;
    vector<int> v;
    vector<int> result;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i=0;i<n;i++){
        while(!s.empty()&&s.top().first<=v[i]){
            s.pop();
        }
        if(s.empty()){
            result.push_back(0);
        }else{
            result.push_back(s.top().second);
        }
        s.push(make_pair(v[i],i+1));
    }
    for(int i=0;i<n;i++){
        cout << result[i] << ' ';
    }
}