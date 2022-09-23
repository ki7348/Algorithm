#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

struct Struct {
    int x,y,dist;
};

using namespace std;
char gender[1001];
vector<Struct> graph;
int parent[1001];
bool check[1001];

bool compare(Struct s1, Struct s2){
    return s1.dist < s2.dist;
}

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
    if(a == b) return true;
    return false;
}

int main() {
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        char x;
        cin >> x;
        gender[i] = x;
    }

    for(int i=1;i<=n;i++){
        parent[i] = i;
    }

    for(int i=0;i<m;i++){
        int x,y,z;
        cin >> x >> y >> z;
        graph.push_back({x,y,z});
        graph.push_back({y,x,z});
    }

    sort(graph.begin(),graph.end(),compare);
    int answer = 0;

    for(int i=0;i<graph.size();i++){
        if(gender[graph[i].x] == gender[graph[i].y]){
            continue;
        }
        if(!findParent(graph[i].x, graph[i].y)){
            answer += graph[i].dist;
            unionParent(graph[i].x, graph[i].y);
            check[graph[i].x] = true;
            check[graph[i].y] = true;
        }

    }
    bool state = false;
    for(int i=1;i<=n;i++){
        if(!check[i]){
            state = true;
        }
    }
    if(state){
        cout << -1 << '\n';
        return 0;
    }

    cout << answer << '\n';
}