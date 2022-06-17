#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
int t;

	
bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
    cin >> t;
    while(t--){
        int origin, dest;
        cin >> origin >> dest;
        bool check[10001] = {false,};
        queue<pair<int,int>> q;
        q.push({0,origin});
        check[origin] = true;
        bool state = false;
        while(!q.empty()){
            int cnt = q.front().first;
            int val = q.front().second;
            q.pop();
            if(val == dest){
                cout << cnt << '\n';
                state = true;
                break;
            }
            for(int i=1;i<10;i++){
                string temp = to_string(val).substr(1,3);
                string new_val_temp = to_string(i) + temp;
                int new_val = stoi(new_val_temp);
                if(!check[new_val] && isPrime(new_val)){
                    check[new_val] = true;
                    q.push({cnt+1,new_val});
                }
            }
            for(int i=0;i<10;i++){
                string temp = to_string(val).substr(0,1);
                string temp2 = to_string(val).substr(2,2);
                string new_val_temp = temp + to_string(i) + temp2;
                int new_val = stoi(new_val_temp);
                if(!check[new_val] && isPrime(new_val)){
                    check[new_val] = true;
                    q.push({cnt+1,new_val});
                }
            }
            for(int i=0;i<10;i++){
                string temp = to_string(val).substr(0,2);
                string temp2 = to_string(val).substr(3,1);
                string new_val_temp = temp + to_string(i) + temp2;
                int new_val = stoi(new_val_temp);
                if(!check[new_val] && isPrime(new_val)){
                    check[new_val] = true;
                    q.push({cnt+1,new_val});
                }
            }
            for(int i=0;i<10;i++){
                string temp = to_string(val).substr(0,3);
                string new_val_temp = temp + to_string(i);
                int new_val = stoi(new_val_temp);
                if(!check[new_val] && isPrime(new_val)){
                    check[new_val] = true;
                    q.push({cnt+1,new_val});
                }
            }
        }
        if(!state){
            cout << "Impossible" << '\n';
        }
    }
}
