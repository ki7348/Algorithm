#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int graph[201];
int d[201];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> graph[i];
    }
    fill(d,d+201,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(graph[i] > graph[j])
                d[i] = max(d[i],d[j]+1);
        }
    }
    int max_elem = 0;
    for(int i=0;i<201;i++){
        max_elem = max(max_elem,d[i]);
    }
    cout << n - max_elem << '\n';
}