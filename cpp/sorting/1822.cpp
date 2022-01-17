#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    map<long long, int> m;
    map<long long, int>::iterator iter;
    long long count = 0;
    vector<long long> result;
    for (int i = 0; i < a; i++)
    {
        long long x;
        cin >> x;
        m[x] += 1;
    }
    for (int i = 0; i < b; i++)
    {
        long long x;
        cin >> x;
        if (m[x] > 0)
        {
            m[x] -= 1;
        }
    }
    for (iter = m.begin(); iter != m.end(); iter++)
    {
        if (iter->second > 0)
        {
            count++;
            result.push_back(iter->first);
        }
    }
    cout << count << '\n';
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
}