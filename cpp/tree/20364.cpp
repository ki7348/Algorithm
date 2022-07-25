#include <iostream>
#include <vector>

using namespace std;
int n, q;
bool graph[1048577];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        int start = x;
        while(!graph[start] && start > 1){
            start /= 2;
        }
        if(start == 1){
            cout << 0 << '\n';
            graph[x] = true;
        } else {
            vector<int> check;
            while(start > 1) {
                if(graph[start]){
                    check.push_back(start);
                }
                start /= 2;
            }
            cout << check.back() << '\n';
        }
    }
}