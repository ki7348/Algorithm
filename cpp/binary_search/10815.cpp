#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> v;
    vector<long long> result;

    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        long long x;
        cin >> x;
        if (binary_search(v.begin(), v.end(), x))
        {
            result.push_back(1);
        }
        else
        {
            result.push_back(0);
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << result[i] << ' ';
    }
}