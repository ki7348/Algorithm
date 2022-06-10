#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int c;
vector<pair<int,int>> v;
struct queueProps {
    int first_elem, second_elem, cnt;
};

int main() {
    cin >> c;

    for(int i=0;i<c;i++){
        int x,y;
        cin >> x >> y;
        queue<queueProps> q;
        q.push({x,y,0});
        while(!q.empty()){
            queueProps now = q.front();
            int cur = now.first_elem;
            int target = now.second_elem;
            q.pop();
            if(cur > target){
                continue;
            }
            if(cur == target){
                cout << now.cnt << '\n';
                break;
            }
            int next = cur * 2;
            q.push({next,target+3,now.cnt+1});
            int plus1 = cur + 1;
            q.push({plus1,target,now.cnt+1});
        }
    }
}