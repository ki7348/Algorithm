#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int n;
bool check[9];

void back_tracking(int index){
    if(index==n){
        for(int i=0;i<v.size();i++)
            cout << v[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=1;i<n+1;i++){
        if(check[i])
            continue;
        check[i] = true;
        v.push_back(i);
        back_tracking(index+1);
        check[i] =false;
        v.pop_back();
    }
}

int main(){
    cin >> n;
    back_tracking(0); 
}