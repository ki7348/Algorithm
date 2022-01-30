#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,k;
vector<int> v;
vector<int> result;
bool check[9];

void back_tracking(int index,int idx){
    if(index==k){
        for(int i=0;i<result.size();i++)
            cout << v[result[i]] << ' ';
        cout << '\n';
        return;
    }
    int temp = 0;
    for(int i=idx;i<n;i++){
        if(check[i] || temp==v[i])
            continue;
        check[i] = true;
        result.push_back(i);
        temp = v[i];
        back_tracking(index+1,i);
        result.pop_back();
        check[i] = false;
    }
}


int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    back_tracking(0,0);

}