#include <iostream>
#include <string>

using namespace std;

string video[64];

void printCompResult(int size, int x, int y){
    char curr = video[x][y];

    for (int i = x; i < x + size; i++)
        for (int j = y; j < y + size; j++)
            if (video[i][j] != curr){
                cout << '(';
                printCompResult(size / 2, x, y);
                printCompResult(size / 2, x, y + size / 2);
                printCompResult(size / 2, x + size / 2, y);
                printCompResult(size / 2, x + size / 2, y + size / 2);
                cout << ')';
                return;
            }

    cout << curr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> video[i];

    printCompResult(n, 0, 0);

    return 0;
}