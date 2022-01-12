#include <iostream>
#include <map>
#include <vector>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        map<int,int> m;
        map<int,int>::iterator iter;
        vector<string> v;
        vector<string> result;
        int n;
        cin >> n;
        string str[n];
        for(int k=0;k<n;k++){
            string x;
            cin >> x;
            v.push_back(x);
        }
        for(int k=0;k<n;k++){
            string x;
            cin >> x;
            for(int a=0;a<v.size();a++){
                if(v[a]==x){
                    m[k] = a - k;
                }
            }
        }
        for(int k=0;k<n;k++){
            string x;
            cin >> x;
            result.push_back(x);
        }
        for(int k=0;k<result.size();k++){
            str[k+m[k]] = result[k];
        }
        for(int k=0;k<n;k++){
            cout << str[k] << ' ';
        }
        cout << '\n';
    }
}
