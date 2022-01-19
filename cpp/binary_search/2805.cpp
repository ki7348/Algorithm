#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<long long> &arr, long long target, long long start, long long end)
{
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long temp = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if(arr[i]>mid)
                temp += arr[i] - mid;
        }
        if (temp < target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return end;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    long long m;
    cin >> m;
    vector<long long> v;
    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    long long result = binarySearch(v,m,0,v.back());
    cout << result <<'\n';
}