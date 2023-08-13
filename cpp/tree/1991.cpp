#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Tree{
    int left, right;
};

int n;
Tree graph[27];

void preOrder(char root){
    if(root == '.'){
        return;
    }
    cout << root;
    preOrder(graph[root - 'A'].left);
    preOrder(graph[root - 'A'].right);
};

void inOrder(char root){
    if(root == '.')
        return;
    inOrder(graph[root - 'A'].left);
    cout << root;
    inOrder(graph[root - 'A'].right);
}

void postOrder(char root){
    if(root == '.')
        return;
    postOrder(graph[root - 'A'].left);
    postOrder(graph[root - 'A'].right);
    cout << root;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        char parent, left, right;
        cin >> parent >> left >> right;
        graph[parent - 'A'].left = left;
        graph[parent - 'A'].right = right;
    }

    preOrder('A');
    cout << '\n';

    inOrder('A');
    cout << '\n';

    postOrder('A');
    cout << '\n';
}
