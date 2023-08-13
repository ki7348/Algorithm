#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int parent[10001];
bool check[10001];
vector<int> fee;

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]); 
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (fee[a] >= fee[b]) parent[a] = b;
	else parent[b] = a;
}

bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return 1;
	else return 0;
}


int main() {
    int n,m,k;
    cin >> n >> m >> k;

    
    fee.push_back(0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        fee.push_back(x);
    }

    for(int i=1;i<=n;i++){
        parent[i] = i;
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        unionParent(a,b);
    }


    int fees = 0;
    for(int i=1;i<=n;i++){
        if(check[getParent(i)]){
            continue;
        }
        fees += fee[getParent(i)];
        check[getParent(i)] = true;
    }


    if(fees > k){
        cout << "Oh no" << '\n';
        return 0;
    }
    cout << fees << '\n';

}