#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        queue<pair<int,int>> result;
        int a,b;
        cin >> a >> b;
        for(int j=0;j<a;j++){
            int c;
            cin >> c;
            q.push(make_pair(c,j));
            pq.push(c);
        }
        while(!q.empty()){
            while(pq.top()!=q.front().first){
                int temp_a = q.front().first;
                int temp_b = q.front().second;
                q.pop();
                q.push(make_pair(temp_a,temp_b));                
            }
            int first = q.front().first;
            int second = q.front().second;
            result.push(make_pair(first,second));
            q.pop();
            pq.pop();
        }
        int result_size = result.size();
        int cnt = 1;
        for(int i=0;i<result_size;i++){
            int temp = result.front().second;
            if(temp==b){
                cout << cnt << '\n';
            }
            result.pop();
            cnt++;
        }
    }
}