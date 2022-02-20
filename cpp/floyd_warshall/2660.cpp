#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

int n,m;
int graph[51][51];

int main(){
    cin >> n;
    for(int i=0;i<51;i++){
        fill(graph[i],graph[i]+51,INF);
    }

    for(int a=1;a<=n;a++){
        for(int b=1;b<=n;b++){
            if(a==b){
                graph[a][b] = 0;
            }
        }
    }

    while(1){
        int a,b;
        cin >> a >> b;
        if(a==-1 && b==-1){
            break;
        }
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
            }
        }
    }
    vector<int> v;
    for(int i=1;i<=n;i++){
        int max_val = 0;
        for(int j=1;j<=n;j++){
            max_val = max(max_val,graph[i][j]);
        }
        v.push_back(max_val);
    }
    int result = INF;
    for(int i=0;i<v.size();i++){
        result = min(result,v[i]);
    }
    cout << result << ' ';
    int count = 0;
    vector<int> final;
    for(int i=0;i<v.size();i++){
        if(result == v[i]){
            final.push_back(i+1);
            count++;
        }
    }
    cout << count << '\n';
    for(int i=0;i<final.size();i++){
        cout << final[i] << ' ';
    }
    cout << '\n';
}