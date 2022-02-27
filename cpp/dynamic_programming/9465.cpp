#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int t;

int max(int a,int b,int c){
    int temp;
    if(a>b){
        temp = a;
    }else{
        temp = b;
    }
    if(temp>c){
        return temp;
    }else{
        return c;
    }
}

int main(){
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        int d[100001][2];
        int arr[100001][2];
        for (int j = 1; j <= n; j++) {
			cin >> arr[j][0];
		}
		for (int j = 1; j <= n; j++) {
			cin >> arr[j][1];
		}
        d[1][0] = arr[1][0];
        d[1][1] = arr[1][1];
        d[2][0] = arr[2][0];
        d[2][1] = arr[2][1];
        for(int j=2;j<=n;j++){
            d[j][0] = max(d[j-1][1],d[j-2][1])+arr[j][0];
            d[j][1] = max(d[j-1][0],d[j-2][0])+arr[j][1];
        }
        cout << max(d[n][0],d[n][1]) << '\n';
    }
}