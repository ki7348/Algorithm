#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    deque<int> q;
    deque<int> pick;
    int count = 0;

    for(int i=0;i<n;i++){
        q.push_back(i+1);
    }
    for(int i=0;i<m;i++){
        int temp;
        cin >> temp;
        pick.push_back(temp);
    }
    while(!pick.empty()){
        while(pick.front()!=q.front()){
            if(std::find(q.begin(),q.end(),pick.front())-q.begin()+1<=ceil(double(q.size())/2+0.5)){
                int temp = q.front();
                q.pop_front();
                q.push_back(temp);
                count++;
            }else{
                int temp = q.back();
                q.pop_back();
                q.push_front(temp);
                count++;
            }
        }
        pick.pop_front();
        q.pop_front();
    }

    cout << count;
}

