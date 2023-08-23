#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v;
    set<int> s;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
        s.insert(x);
    }

    set<int>::iterator iter;
    int answer = 1;
    for(iter = s.begin(); iter != s.end(); iter++){
        int elem = *iter;
        int target = v[0];
        int dur = 1;
        for(int i=1;i<v.size();i++){
            if(v[i] == target){
                dur++;
                answer = max(answer,dur);
            }else if(v[i] == elem){
                continue;
            }else{
                dur = 1;
            }
            target = v[i];
        }
    }    

    cout << answer << '\n';


}