#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[500001];
int n,m;


int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]); 
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return 1;
	else return 0;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<500001;i++){
        parent[i] = i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(findParent(a,b)){
            cout << i+1 << '\n';
            return 0;
        }
        unionParent(a,b);
    }
    cout << 0 << '\n';
    return 0;
}