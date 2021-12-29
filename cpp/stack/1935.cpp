#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int x;
    cin >> x;

    stack<double> s;
    vector<int> arr;

    string str;
    cin >> str;

    for(int i = 0;i<x;i++){
        int elem;
        cin >> elem;
        arr.push_back(elem);
    }


    for(int i = 0; i<str.length();i++){
        if(int(str[i])>=65 && int(str[i])<=90){
            s.push(arr[int(str[i])-65]);
        }
        else if (str[i]=='+'){
            double b = s.top();
            s.pop();
            double a = s.top();
            s.pop();
            s.push(a+b);
        }
        else if (str[i]=='*'){
            double b = s.top();
            s.pop();
            double a = s.top();
            s.pop();
            s.push(a*b);
        }
        else if (str[i]=='-'){
            double b = s.top();
            s.pop();
            double a = s.top();
            s.pop();
            s.push(a-b);
        }
        else if (str[i]=='/'){
            double b = s.top();
            s.pop();
            double a = s.top();
            s.pop();
            s.push(a/b);
        }
    }
    double fixed_answer = s.top();
    cout << fixed;
    cout.precision(2);
    cout << fixed_answer;

}