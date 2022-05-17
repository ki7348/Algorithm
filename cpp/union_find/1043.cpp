#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> first;
int parent[51];
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
    int known;
    cin >> known;
    int result = 0;
    vector<int> v;
    for(int i=0;i<51;i++){
        parent[i] = i;
    }
    for(int i=0;i<known;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i=0;i<m;i++){
        int a;
        cin >> a;
        vector<int> temp;
        for(int j=0;j<a;j++){
            int k;
            cin >> k;
            if(j==0){
                first.push_back(k);
            }
            temp.push_back(k);
        }
        for(int j=0;j<temp.size()-1;j++){
            unionParent(temp[j],temp[j+1]);
        }
    }
    for(int i=0;i<m;i++){
        bool state = false;
        for(int j=0;j<v.size();j++){
            if(findParent(v[j],first[i])){
                state = true;
            }
        }
        if(!state){
            result+=1;
        }
    }
    cout << result << '\n';

}