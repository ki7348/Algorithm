#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;

    deque<char> q;

    for(int i=0;i<str.length();i++){
        q.push_back(str[i]);
    }

    int boys = 0;
    int girls = 0;

    int cnt = 0;

    while(!q.empty()){
        char qfront = q.front();
        q.pop_front();

        if(qfront == 'W'){
            if(girls - boys >= n){
                char temp = q.front();
                q.pop_front();
                if(temp == 'M'){
                    boys += 1;
                    q.push_front('W');
                    cnt++;
                    continue;
                } else {
                    cout << cnt << '\n';
                    return 0;
                }
            }   
            girls += 1;
        }else{
            if(boys - girls >= n){
                char temp = q.front();
                q.pop_front();
                if(temp == 'W'){
                    girls += 1;
                    q.push_front('M');
                    cnt++;
                    continue;
                } else {
                    cout << cnt << '\n';
                    return 0;
                }
            }
            boys += 1 ;
        }

        cnt++;
    }
    
    cout << cnt << '\n';
}