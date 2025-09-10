#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string line;
    
    while(getline(cin,line)){
        if(line == ".") break;
        stack<char> st;
        bool isOk = true;
        for(int i=0;i<line.length();i++){
            if(line[i] == '(' || line[i] == '[' ){
                st.push(line[i]);
            }
            else if((line[i] == ')' || line[i] == ']') && st.empty()){
                isOk = false;
                break;
            }
            else if(line[i] == ')'){
                char stTop = st.top();
                if(stTop != '('){
                    isOk = false;
                    break;
                }
                st.pop();
            }
            else if(line[i] == ']'){
                char stTop = st.top();
                if(stTop != '['){
                    isOk = false;
                    break;
                }
                st.pop();
            }
        }
        if(!st.empty())
            isOk = false;
        if(isOk){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }
    return 0;
}