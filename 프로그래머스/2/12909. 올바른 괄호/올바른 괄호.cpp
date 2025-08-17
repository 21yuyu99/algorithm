#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    for(auto x:s){
        if(x=='('){
            st.push(x);
        }
        else{
            if(st.empty()){
                answer = false;
                break;
            }
            else{
                st.pop();
            }
        }
    }
    if(!st.empty()){
        answer = false;
    }

    return answer;
}