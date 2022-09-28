#include <iostream>
#include <algorithm>

using namespace std;
int score[101];

int main(){
    int x;
    cin >> x;
    for(int i=0;i<x;i++){
        int a;
        cin >> a;
        score[i] = a;
    }
    int answer = 0;
    for(int i=x-1;i>=0;i--){
        if(score[i] < score[i-1]){
            answer += score[i-1] - score[i] + 1;
            score[i-1] = score[i] - 1;
        }else if(score[i] == score[i-1]){
            answer += 1;
            score[i-1] = score[i] - 1;
        }
    }
    cout << answer << '\n';
}