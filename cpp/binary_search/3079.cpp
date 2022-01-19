#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long n;
    long long m;
    cin >> n >> m;

    vector<long long> v;
    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        v.push_back(x);
    }

    long long int start = 0;
    long long int end = *max_element(v.begin(),v.end())*m;
    long long int ans;

    while (start <= end)
    {
        long long int mid = (start + end) / 2;
        long long int temp = 0;
        for (int i = 0; i < v.size(); i++)
        {
            temp+=mid/v[i];
        }
        if (temp >= m){
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    cout << ans << '\n';
}