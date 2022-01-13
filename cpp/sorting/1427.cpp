#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int main(){
    string n;
    int a;
    cin >> a;
    n = to_string(a);
    sort(n.begin(),n.end(),greater<char>());
    cout << n;
    cout << '\n';

}