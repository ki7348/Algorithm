#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        vector<int> v;
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        // for(int j=0;j<v.size();j++){
        //     cout << v[j] << '\n';
        // }
        deque<int> temp;
        temp.push_back(v.back());
        v.pop_back();
        while(!v.empty()){
            temp.push_front(v.back());
            v.pop_back();
            if(!v.empty()){
                temp.push_back(v.back());
                v.pop_back();
            }
        }
        int max_diff = 0;
        if(abs(temp[0]-temp.back())>max_diff){
            max_diff = abs(temp[0]-temp.back());
        }
        for(int j=0;j<temp.size()-1;j++){
            if(abs(temp[j]-temp[j+1])>max_diff){
                max_diff = abs(temp[j]-temp[j+1]);
            }
        }
        cout << max_diff << '\n';
    }
}