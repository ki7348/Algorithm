#include <iostream>
#include <map>

using namespace std;

int main(){
    string str;
    map<string,double> m;
    map<string,double>::iterator iter;
    int count = 0;
    while(getline(cin,str)){
        m[str] += 1;
        count++;
    }
    cout << fixed;
    cout.precision(4);
    for(iter=m.begin();iter!=m.end();iter++){
        double temp = (iter->second/count)*100.0;
        cout << iter->first << ' ' << temp << '\n';
    }
}