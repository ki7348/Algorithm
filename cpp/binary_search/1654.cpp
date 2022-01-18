#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int binarySearch(vector<long long> &arr, int target, long long start, long long end)
{
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long temp = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            temp += arr[i] / mid;
        }
        if (temp < target)
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
    int k, n;
    cin >> k >> n;
    vector<long long> v;
    for (int i = 0; i < k; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int result = binarySearch(v, n, 0, pow(2, 31) - 1);
    cout << result << '\n';
}