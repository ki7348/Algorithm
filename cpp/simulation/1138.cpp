#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    vector<int> answer;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    int idx = n;
    for(int i=n-1;i>=0;i--){
        int vi = v[i];
        answer.insert(answer.begin() + vi,idx);
        idx--;
    }

    for(int i=0;i<answer.size();i++){
        cout << answer[i] << ' ';
    }
    cout << '\n';
}