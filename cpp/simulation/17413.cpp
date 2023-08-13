#include <iostream>
#include <algorithm>
#include <vector>
#include<string>

using namespace std;

int main(){
	string str; // 문자열 S
	getline(cin, str);
	str += ' ';


    string temp = "";
    vector<string> strs;
    bool bracket = false;

    for(int i=0;i<str.length();i++){
        if(str[i] == '<'){
            if(temp.length() > 0){
                string temp_reverse = "";
                for(int j=temp.length()-1;j>=0;j--){
                    temp_reverse += temp[j];
                }
                strs.push_back(temp_reverse);
                temp = "";
            }
            bracket = true;
            temp += "<";
        }else if(str[i] == '>'){
            bracket = false;
            temp += ">";
            strs.push_back(temp);
            temp = "";
        }else if(str[i] == ' '){
            if(bracket){
                temp += " ";
            }else{
                string temp_reverse = "";
                for(int j=temp.length()-1;j>=0;j--){
                    temp_reverse += temp[j];
                }
                temp_reverse += " ";
                strs.push_back(temp_reverse);
                temp = "";
            }
        }else{
            temp += str[i];
        }
    }


    for(int i=0;i<strs.size();i++){
        cout << strs[i];
    }
}