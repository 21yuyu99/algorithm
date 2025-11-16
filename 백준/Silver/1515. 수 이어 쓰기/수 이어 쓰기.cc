#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string NStr;
    cin >> NStr;

    int answer = 0;
    int curLen = 0;
    while(curLen<NStr.length()){
        ++answer;
        string ansStr = to_string(answer);

        for(int i=0;i<ansStr.length();i++){
                if(curLen>=NStr.length()) break;
                if(ansStr[i] == NStr[curLen]){ 
                    ++curLen;
                }
        }
    }
    cout << answer;
    return 0;
}
//최대 3000자리.