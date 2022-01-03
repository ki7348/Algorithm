#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    stack<int> temp;
    vector<int> result;

    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        if(result.empty()){
            if(a==1){
                result.push_back(a);
            }else{
                temp.push(a);
            }
        }else{
            if(a==result.back()+1){
                result.push_back(a);
            }else{
                temp.push(a);
            }
        }
        while(true){
            if(temp.empty()){
                break;
            }
            if(result.empty()){
                break;
            }
            if(temp.top()!=result.back()+1){
                break;
            }
            result.push_back(temp.top());
            temp.pop();
        }
    }

    int count = 0;
    for(int i=0;i<n;i++){
        if(result[i]==i+1){
            count+=1;
        }
    }
    if(count==n){
        cout << "Nice" << '\n';
    }else{
        cout << "Sad" << '\n';
    }

}