#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a,b;
    cin >> a >> b;

    int c;
    cin >> c;
    
    vector<int> v;

    for(int i=0;i<n;i++){
        int d;
        cin >> d;
        v.push_back(d);
    }

    sort(v.begin(),v.end());

    int last = c;
    float price = a;
    float answer = c / a;
    for(int i=0;i<n;i++){
        last += v.back();
        v.pop_back();

        price += b;

        float temp = last / price;

        answer = max(answer,temp);
        
    }

    cout << floor(answer) << '\n';
}