#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int result = 0;
        vector<pair<int, int>> v;
        stack<pair<int, int>> s;
        for (int j = 0; j < n; j++)
        {
            int a, b;
            cin >> a >> b;
            v.push_back(make_pair(a, b));
        }
        sort(v.begin(), v.end());
        for (int j = 0; j < v.size(); j++)
        {
            if (j == 0)
            {
                s.push(make_pair(v[j].first, v[j].second));
            }
            else
            {
                if (s.top().second > v[j].second)
                {
                    s.push(make_pair(v[j].first, v[j].second));
                }
                else
                {
                    result += 1;
                }
            }
        }
        cout << n - result << '\n';
    }
}