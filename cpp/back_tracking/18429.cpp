#include <iostream>
#include <vector>

using namespace std;
int n,k;
bool check[9];
vector<int> v;
vector<int> result;
int count = 0;

void back_tracking(int index){
    if(index==n){
        int temp = 500;
        int cnt = 0;
        for(int i=0;i<result.size();i++){
            temp += v[result[i]];
            temp -= k;
            if(temp>=500){
                cnt+=1;
            }
        }
        if(cnt==n){
            count ++;
        }
        return;
    }
    for(int i=1;i<v.size();i++){
        if(check[i])
            continue;
        check[i] = true;
        result.push_back(i);
        back_tracking(index+1);
        result.pop_back();
        check[i] = false;
    }

}

int main(){
    cin >> n >> k;
    v.push_back(0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    back_tracking(0);
    cout << count <<'\n';
}