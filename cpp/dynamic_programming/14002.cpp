#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> v;
int d[1001];
int result = 0;
vector<int> seq;

int main() {
    cin >> n;
    v.push_back(0);
    fill(d,d+1001,1);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    if(v.size()==2){
        cout << 1 << '\n';
        cout << v[1] << '\n';
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(v[i]>v[j]){
                d[i] = max(d[i],d[j]+1);
            }
            result = max(result,d[i]);
        }
    }
    int initial = 0;
    int cur = 0;
    cout << result << '\n';
    for(int i=1;i<=n;i++){
        if(d[i] == result){
            seq.push_back(v[i]);
            initial = i;
            cur = result;
            break;
        }
    }
    for(int i=initial-1;i>=1;i--){
        if(d[i] == cur - 1){
            seq.push_back(v[i]);
            cur = d[i];
        }
    }
    for(int i=seq.size()-1;i>=0;i--){
        cout << seq[i] << ' ';
    }
    cout << '\n';
}