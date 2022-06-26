#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;

bool compare(int x,int y){
    return x > y;
}

int main() {
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end(),compare);
    int result = 0;
    for(int i=0;i<n;i++){
        v[i] += i + 2;
    }
    cout << *max_element(v.begin(), v.end()) << '\n';
}