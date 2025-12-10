#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A,B;
    cin >> A >> B;
    int cnt = 0;
    while(B>A){
        string strB = to_string(B);
        if(strB[strB.length()-1] == '1'){
            strB = strB.substr(0,strB.length()-1); //1 제거
            B = stoi(strB);
        }
        else if(B%2==0){
            B/=2;
        }
        else{
            cnt = -1;
            break;
        }
        ++cnt;
    }
    if(B==A){
        cout << cnt+1;
    }
    else{
        cout << -1;
    }
    return 0;
}