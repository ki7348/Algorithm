#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, long long target, int start, int end)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        long long temp = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > mid)
                temp += mid;
            else
                temp += arr[i];
        }
        if (temp > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return end;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    long long m;
    cin >> m;
    sort(v.begin(), v.end());
    long long result = binarySearch(v, m, 0, v.back());
    cout << result << '\n';
}