#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int limit = 0;
string str;
bool check[51];

vector<int> temp;
vector<string> answers;

void back_tracking(int index, int idx){
    if(index == 2){
        int first = temp[0];
        int second = temp[1];


        string answer = "";
        string first_str = str.substr(0,first+1);
        string second_str = str.substr(first+1,second-first);
        string third_str = str.substr(second+1);

        reverse(first_str.begin(), first_str.end());
        reverse(second_str.begin(), second_str.end());
        reverse(third_str.begin(), third_str.end());

        answer += first_str;
        answer += second_str;
        answer += third_str;


        answers.push_back(answer);

        return;
    }
    for(int i=idx;i<limit-1;i++){
        if(check[i]){
            continue;
        }
        check[i] = true;
        temp.push_back(i);
        back_tracking(index+1, i);
        temp.pop_back();
        check[i] = false;
    }
}

int main() {
    cin >> str;

    limit = str.length();
    back_tracking(0,0);

    sort(answers.begin(),answers.end());

    cout << answers[0] << '\n';
}