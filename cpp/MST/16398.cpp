#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

struct Struct {
    int x,y,dist;
};

using namespace std;
vector<Struct> v;
int parent[1001];

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
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            if(i != j){
                v.push_back({i,j,x});
            }
        }
    }

    sort(v.begin(),v.end(), compare);

    long long result = 0;

    for(int i=0;i<v.size();i++){
        if(findParent(v[i].x,v[i].y)){
            continue;
        }
        unionParent(v[i].x, v[i].y);
        result += v[i].dist;
    }

    cout << result << '\n';

}