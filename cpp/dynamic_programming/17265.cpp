#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9

using namespace std;
int n;
char graph[6][6];
int d[6][6];
int d2[6][6];

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char x;
            cin >> x;
            graph[i][j] = x;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j] = -INF;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d2[i][j] = INF;
        }
    }
    d[1][1] = graph[1][1] - '0';
    d2[1][1] = graph[1][1] - '0';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == 1 && j == 1){
                continue;;
            }
            if(graph[i][j] == '+' || graph[i][j] == '*' || graph[i][j] == '-'){
                continue;
            }
            char up = graph[i-1][j];
            char left = graph[i][j-1];
            if(up == '+'){
                if(j>=2){
                    d[i][j] = d[i-1][j-1] + (graph[i][j] - '0');
                }
                if(i>=3){
                    d[i][j] = max(d[i][j], d[i-2][j] + (graph[i][j] - '0'));
                }
            } else if(up == '*'){
                if(j>=2){
                    d[i][j] = d[i-1][j-1] * (graph[i][j] - '0');
                }
                if(i>=3){
                    d[i][j] = max(d[i][j], d[i-2][j] * (graph[i][j] - '0'));
                }
            } else if(up == '-'){
                if(j>=2){
                    d[i][j] = d[i-1][j-1] - (graph[i][j] - '0');
                }
                if(i>=3){
                    d[i][j] = max(d[i][j], d[i-2][j] - (graph[i][j] - '0'));
                }
            }
            if (left == '+'){
                if(i>=2){
                    d[i][j] = max(d[i][j], d[i-1][j-1] + (graph[i][j] - '0'));
                }
                if(j>=3){
                    d[i][j] = max(d[i][j], d[i][j-2] + (graph[i][j] - '0'));
                }
            } else if(left == '*'){
                if(i>=2){
                    d[i][j] = max(d[i][j], d[i-1][j-1] * (graph[i][j] - '0'));
                }
                if(j>=3){
                    d[i][j] = max(d[i][j], d[i][j-2] * (graph[i][j] - '0'));
                }
            } else if(left == '-'){
                if(i>=2){
                    d[i][j] =max(d[i][j],  d[i-1][j-1] - (graph[i][j] - '0'));
                }
                if(j>=3){
                    d[i][j] = max(d[i][j], d[i][j-2] - (graph[i][j] - '0'));
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == 1 && j == 1){
                continue;
            }
            if(graph[i][j] == '+' || graph[i][j] == '*' || graph[i][j] == '-'){
                continue;
            }
            char up = graph[i-1][j];
            char left = graph[i][j-1];
            if(up == '+'){
                if(j>=2){
                    d2[i][j] = d2[i-1][j-1] + (graph[i][j] - '0');
                }
                if(i>=3){
                    d2[i][j] = min(d2[i][j], d2[i-2][j] + (graph[i][j] - '0'));
                }
            } else if(up == '*'){
                if(j>=2){
                    d2[i][j] = d2[i-1][j-1] * (graph[i][j] - '0');
                }
                if(i>=3){
                    d2[i][j] = min(d2[i][j], d2[i-2][j] * (graph[i][j] - '0'));
                }
            } else if(up == '-'){
                if(j>=2){
                    d2[i][j] = d2[i-1][j-1] - (graph[i][j] - '0');
                }
                if(i>=3){
                    d2[i][j] = min(d2[i][j], d2[i-2][j] - (graph[i][j] - '0'));
                }
            }
            if (left == '+'){
                if (i>=2){
                    d2[i][j] = min(d2[i][j], d2[i-1][j-1] + (graph[i][j] - '0'));
                }
                if(j>=3){
                    d2[i][j] = min(d2[i][j], d2[i][j-2] + (graph[i][j] - '0'));
                }
            } else if(left == '*'){
                if (i>=2){
                    d2[i][j] = min(d2[i][j], d2[i-1][j-1] * (graph[i][j] - '0'));
                }
                if(j>=3){
                    d2[i][j] = min(d2[i][j], d2[i][j-2] * (graph[i][j] - '0'));
                }
            } else if(left == '-'){
                if (i>=2){
                    d2[i][j] =min(d2[i][j],  d2[i-1][j-1] - (graph[i][j] - '0'));
                }
                if(j>=3){
                    d2[i][j] = min(d2[i][j], d2[i][j-2] - (graph[i][j] - '0'));
                }
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << d[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << d[n][n] << ' ' << d2[n][n]  << '\n';
}