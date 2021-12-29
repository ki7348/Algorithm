#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> s;

    int x;
    cin >> x;

    for(int i = 0; i < x; i++){
        int num;
        cin >> num;
        if(num != 0){
            s.push(num);
        }
        else{
            s.pop();
        }
    }
    int sum = 0;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        sum += s.top();
        s.pop();
    }
    cout << sum;
    return 0;
}