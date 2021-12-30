#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    stack<int> s;
    vector<char> v;
    int cnt = 1;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;

        while (cnt <= x){
            s.push(cnt);
            cnt+=1;
            v.push_back('+');
        }
        if(s.top()==x){
            s.pop();
            v.push_back('-');
        }else{
            cout << "NO";
            return 0;
        }
    }

    for(int i=0;i<v.size();i++){
        cout << v[i] << '\n';
    }


}