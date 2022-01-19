#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        map<int, int> m;
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            m[x] += 1;
        }
        int test;
        cin >> test;
        for(int j=0;j<test;j++){
            int x;
            cin >> x;
            if(m[x]>0){
                cout << 1 << '\n';
            }else{
                cout << 0 << '\n';
            }
        }
    }
}