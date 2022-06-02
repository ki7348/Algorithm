#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
string str;
int d[1001];

int main(){
    cin >> n;
    cin >> str;
    fill(d,d+1001,1e9);
    d[0] = 0;
    for(int i=0;i<n;i++){
        if(str[i] == 'B'){
            for(int j=0;j<i;j++){
                if(str[j] == 'J'){
                    d[i] = min(d[i],d[j] + (i-j)*(i-j));
                }
            }
        }else if(str[i] == 'O'){
            for(int j=0;j<i;j++){
                if(str[j] == 'B'){
                    d[i] = min(d[i],d[j] + (i-j)*(i-j));
                }
            }
        }else{
            for(int j=0;j<i;j++){
                if(str[j] == 'O'){
                    d[i] = min(d[i],d[j] + (i-j)*(i-j));
                }
            }
        }
    }
    if(d[n-1] == 1e9){
        cout << -1<< '\n';
    }else{
        cout << d[n-1] << '\n';
    }
}