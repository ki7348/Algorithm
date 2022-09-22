#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
vector<int> graph[100001];
int parent[100001];

int getParent(int x){
    if(x == parent[x]) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

bool findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a != b) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        unionParent(a,b);
    }
    vector<int> sche;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        sche.push_back(x);
    }
    int answer = 0;
    for(int i=0;i<n-1;i++){
        if(!findParent(sche[i],sche[i+1])){
            answer += 1;
        }
    }

    cout << answer << '\n';
    

}