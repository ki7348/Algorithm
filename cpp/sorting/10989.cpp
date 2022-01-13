#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int v[10001] = {};

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v[x] +=1;
    }
    for(int i=0;i<10001;i++){
        if(v[i]!=0){
            for(int j=0;j<v[i];j++){
                cout << i << '\n';
            }
        }
    }


}