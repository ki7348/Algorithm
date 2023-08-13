#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct Tree {
    int left, right;
};

Tree graph[51];
bool check[51];

int main(){
    int n;
    cin >> n;

    for(int i=0;i<51;i++){
        graph[i].left = -1;
        graph[i].right = -1;
    }

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x >= 0 && graph[x].left >= 0){
            graph[x].right = i;
        }else if(x >= 0 && graph[x].left == -1){
            graph[x].left = i;
        }
    }

    int target;
    cin >> target;

    vector<int> targets;
    targets.push_back(target);

    while(!targets.empty()){
        int target = targets.back();
        targets.pop_back();
        if(graph[target].left >= 0){
            targets.push_back(graph[target].left);
        }
        if(graph[target].right >= 0){
            targets.push_back(graph[target].right);
        }
        check[target] = true;
    }

    int answer = 0;
    for(int i=0;i<=n-1;i++){
        if(!check[i] && graph[i].left == -1 && graph[i].right == -1){
            answer++;
        }else if(!check[i] && check[graph[i].left] && graph[i].right == -1){
            answer++;
        }else if(!check[i] && check[graph[i].right] && graph[i].left == -1){
            answer++;
        }
    }


    cout << answer << '\n';
}