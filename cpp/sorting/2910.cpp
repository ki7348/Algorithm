#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

bool compare(tuple<long long,int,int>a,tuple<long long,int,int>b){
    if(get<1>(a)==get<1>(b)){
        return get<2>(a) < get<2>(b);
    }
    return get<1>(a) > get<1>(b);
}

int main(){
    int n;
    cin >> n;
    long long c;
    cin >> c;

    vector<tuple<long long,int,int>> v;

    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        for(int j=0;j<v.size();j++){
            if(get<0>(v[j])==x){
                get<1>(v[j])+=1;
            }
        }
        v.push_back(make_tuple(x,1,i));
        
    }
    sort(v.begin(),v.end(),compare);
    // for(int i=0;i<v.size();i++){
    //     cout << get<0>(v[i]) << ' ' << get<1>(v[i]) << ' ' << get<2>(v[i]) << '\n';
    // }
    vector<int> result;
    for(int i=0;i<v.size();i++){
        auto it = find(result.begin(), result.end(), get<0>(v[i]));
        if(it!=result.end()){
            continue;
        }else{
            for(int j=0;j<get<1>(v[i]);j++)
                result.push_back(get<0>(v[i]));
        }

    }
    for(int i=0;i<result.size();i++){
        cout << result[i] << '\n';
    }


}