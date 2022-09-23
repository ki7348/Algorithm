#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1e9

struct Struct {
    int x,y,dist;
};

using namespace std;
int parent[1001];
vector<Struct> graph;

bool compare(Struct g1, Struct g2){
    return g1.dist > g2.dist;
}

int getParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y){
    x = getParent(x);
    y = getParent(y);
    if(x > y ) parent[x] = y;
    else parent[y] = x;
}

bool findParent(int x, int y){
    x = getParent(x);
    y = getParent(y);

    if(x == y) return true;
    return false;
}

int main(){
    int p,w;
    cin >> p >> w;
    int c,v;
    cin >> c >> v;
    int min_elem = INF;

    for(int i=0;i<p;i++){
        parent[i] = i;
    }

    for(int i=0;i<w;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph.push_back({a,b,c});
        graph.push_back({b,a,c});
    }

    sort(graph.begin(),graph.end(),compare);

    for(int i=0;i<graph.size();i++){
        if(findParent(graph[i].x, graph[i].y)){
            continue;
        }
        unionParent(graph[i].x, graph[i].y);
        min_elem = min(min_elem, graph[i].dist);
        if(findParent(c,v)) {
            break;
        }
    }

    cout << min_elem << '\n';
}