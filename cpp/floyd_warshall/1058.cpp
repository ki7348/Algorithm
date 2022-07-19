#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9

using namespace std;
int graph[51][51];
char c_graph[51][51];
int n;

int main() {
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> c_graph[i][j];
        }
    }

    for(int i=0;i<n;i++){
        fill(graph[i],graph[i]+51,INF);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j){
                graph[i][j] = 0;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(c_graph[i][j] == 'Y'){
                graph[i][j] = 1;
            }
        }
    }

   for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
            }
        }
    }

    int result = 0;
    for(int i=0;i<n;i++){
        int temp_sum = 0;
        for(int j=0;j<n;j++){
            if(graph[i][j] <=2  && graph[i][j] > 0){
                temp_sum++;
            }
        }
        result = max(result,temp_sum);
    }
    cout << result << '\n';
}