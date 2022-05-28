#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int graph[21][21];
bool check[21];
vector<int> temp;
vector<int> enemy;
int result = 1e9;

void back_tracking(int index,int idx) {
    if(index == n/2){
        enemy.clear();
        for(int i=1;i<=n;i++){
            if(find(temp.begin(), temp.end(), i) == temp.end()){
                enemy.push_back(i);
            }
        }
        int first_sum = 0;
        int second_sum = 0;
        for(int i=1;i<temp.size();i++){
            for(int j=0;j<i;j++){
                first_sum += graph[temp[i]][temp[j]];
                first_sum += graph[temp[j]][temp[i]];
            }
        }
        for(int i=1;i<enemy.size();i++){
            for(int j=0;j<i;j++){
                second_sum += graph[enemy[i]][enemy[j]];
                second_sum += graph[enemy[j]][enemy[i]];
            }
        }
        result = min(result,abs(first_sum-second_sum));
        return;
    }
    for(int i=idx;i<=n;i++){
        if(check[i])
            continue;;
        temp.push_back(i);
        check[i] = true;
        back_tracking(index+1, i);
        check[i] = false;
        temp.pop_back();
    }
}

int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> graph[i][j];
        }
    }
    back_tracking(0,1);
    cout << result << '\n';
}