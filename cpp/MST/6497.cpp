#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

struct Struct{
    int a,b,dist;
};

using namespace std;
int parent[100001];
vector<Struct> v;

bool compare(Struct v1, Struct v2){
    return v1.dist < v2.dist;
}

int getParent(int x){
    if(parent[x] == x) return x;
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
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,dist;
        cin >> a >> b >> dist;
        v.push_back({a,b,dist});
        v.push_back({b,a,dist});
    }

    for(int i=1;i<=n;i++){
        parent[i] = i;
    }

    sort(v.begin(),v.end(),compare);

    int answer = 0;
    int max_elem = 0;
    for(int i=0;i<v.size();i++){
        if(findParent(v[i].a,v[i].b)) continue;
        unionParent(v[i].a,v[i].b);
        answer += v[i].dist;
        max_elem = max(max_elem, v[i].dist);
    }

    cout << answer - max_elem << '\n';

}