#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    string origin;
    cin >> origin;
    string target;
    cin >> target;

    vector<char> start;
    for(int i=0;i<target.size();i++){
        start.push_back(target[i]);
    }

    while(start.size() > 0){
        if(start.size() == origin.size()){
            for(int i=0;i<start.size();i++){
                if(origin[i] != start[i]){
                    cout << 0 << '\n';
                    return 0;
                }
            }
            cout << 1 << '\n';
        }
        if(start.back() == 'A'){
            start.pop_back();
        }else if(start.back() == 'B'){
            reverse(start.begin(),start.end());
            start.pop_back();
        }else{
            cout << 0 << '\n';
            return 0;
        }
    }
    
}