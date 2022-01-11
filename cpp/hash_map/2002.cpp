#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<string,int> m;
    vector<int> v;
    int result = 0;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;

        m[str] = i;
    }
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        v.push_back(m[str]);
    }
    for(int i=0;i<v.size();i++){
        for(int j=i;j<v.size();j++){
            if(v[i]>v[j]){
                result+=1;
                break;
            }
        }
    }
    cout << result << '\n';
}