#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int result[10001] = {};

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    int total = 0;
    int index = 0;

    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end(),compare);

    for(int i=0;i<n;i++){
        int temp = v.back().first;
        int temp2 = v.back().second;
        temp2-=1;
        if(result[temp2]==0){
            result[temp2] = temp;
        }else{
            while(result[temp2]!=0){
                temp2--;
                if(temp2<0){
                    break;
                }
            }
            result[temp2]=temp;
        }
        v.pop_back();
    }
    for(int i=0;i<10001;i++){
        total+=result[i];
    }


    cout << total << '\n';

}