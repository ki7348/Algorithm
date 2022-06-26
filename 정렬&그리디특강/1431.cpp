#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<string> v;

bool compare(string str1, string str2){
    if(str1.length() != str2.length()){
        return str1.length() < str2.length();
    }
    int sum1 = 0;
    int sum2 = 0;
    for(int i=0;i<str1.length();i++){
        if(str1[i] - '0' > 0 && str1[i] - '0' <= 9){
            sum1+= str1[i] - '0';
        }
    }
    for(int i=0;i<str2.length();i++){
        if(str2[i] - '0' > 0 && str2[i] - '0' <= 9){
            sum2+= str2[i] - '0';
        }
    }
    if(sum1 != sum2){
        return sum1 < sum2;
    }
    return str1 < str2;
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<n;i++){
        cout << v[i] << '\n';
    }
}