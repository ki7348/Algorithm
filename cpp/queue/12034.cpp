#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int p;
        cin >> p;
        deque<int> dq;
        for(int j=0;j<2*p;j++){
            int n;
            cin >> n;
            dq.push_back(n);
        }
        vector<int> result;
        for(int i=0; i<dq.size(); i++){
            int now = dq[i];
            if(now == 0)
                continue;
            int origin = now/3;
            origin *= 4;
            for(int j=i+1; j<dq.size(); j++){
                if(dq[j] == origin){
                    result.push_back(now);
                    dq[j] = 0;
                    break;
                }
            }
        }
        cout << "Case #" << i+1 << ": ";
        for(int j=0;j<result.size();j++){
            cout << result[j] << ' ';
        }
        cout << '\n';
    }
}