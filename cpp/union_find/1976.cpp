#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int parent[201];
vector<int> final;

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
    for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin >> x;
            if(x==1){
                unionParent(i,j);
            }
        }
    }
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        final.push_back(x);
    }
    int root = getParent(final[0]);
    for(int i=1;i<final.size();i++){
        if(getParent(final[i])!=root){
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}