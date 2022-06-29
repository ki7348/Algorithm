#include <iostream>
#include <algorithm>
#include <vector>

struct Bindo {
    int cnt, idx, num;
};

using namespace std;
int n,c;
vector<Bindo> v;

bool compare(Bindo v1, Bindo v2){
    int cnt1 = v1.cnt;
    int idx1 = v1.idx;
    int num1 = v1.num;

    int cnt2 = v2.cnt;
    int idx2 = v2.idx;
    int num2 = v2.num;

    if(cnt1 != cnt2)
        return cnt1 > cnt2;
    return idx1 < idx2;
}

int main() {
    cin >> n >> c;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        bool is_found = false;
        for(int j=0;j<v.size();j++){
            if(v[j].num == x){
                v[j].cnt++;
                is_found = true;
            }
        }
        if(is_found == false){
            v.push_back({1,i,x});
        }
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].cnt; j++){
            cout << v[i].num << ' ';
        }
    }
    return 0;
}