#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> v1;
vector<int> v2;

bool compare(int x,int y){
    return x > y;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v1.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v2.push_back(x);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end(),compare);
    int result = 0;
    for(int i=0;i<n;i++){
        result += v1[i] * v2[i];
    }
    cout << result << '\n';
}