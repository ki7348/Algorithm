#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long binarySearch(vector<long long> &arr, long long target, long long start, long long end)
{
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        vector<int> temp;
        int count = 0;
        temp.push_back(arr[0]);
        for (int i = 1; i < arr.size(); i++)
        {
            if(arr[i]-temp.back()>=mid)
                temp.push_back(arr[i]);
        }
        if (temp.size() < target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return end;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,c;
    cin >> n >> c;
    vector<long long> v;

    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    long long result = binarySearch(v,c,0,v.back());
    cout << result << '\n';
}