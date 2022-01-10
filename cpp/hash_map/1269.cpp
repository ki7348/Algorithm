#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    map<int,int> m;
    map<int,int> m2;
    map<int,int>::iterator iter;
    map<int,int>::iterator iter2;
    vector<int> temp;
    for(int i=0;i<a;i++){
        int a_elem;
        cin >> a_elem;
        temp.push_back(a_elem);
        m[a_elem] += 1;
    }
    for(int j=0;j<b;j++){
        int b_elem;
        cin >> b_elem;
        m2[b_elem] += 1;
        if(m[b_elem]>0){
            m[b_elem]-=1;
        }
    }
    int temp_size = temp.size();
    for(int i=temp_size-1;i>=0;i--){
        if(m2[temp[i]]>0){
            m2[temp[i]] -= 1;
        }
        temp.pop_back();
    }
    int total = 0;
    for(iter=m.begin();iter!=m.end();iter++){
        if(iter->first>0){
            total+=iter->second;
        }
    }
    for(iter2=m2.begin();iter2!=m2.end();iter2++){
        if(iter2->first>0){
            total+=iter2->second;
        }
    }
    cout << total << '\n';

}