#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<long long> v;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        long long x;
        cin >> x;
        if (binary_search(v.begin(), v.end(), x))
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
}
