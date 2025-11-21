#include <iostream>
#include <string>
using namespace std;
char vowel[5] = {'a','i','o','u','e'};
bool isVowel(char a){
    for(int i=0;i<5;i++){
        if(a==vowel[i]) return true;
    }
    return false;
}
bool repeatVowel3Time(int curIdx,string input){
    int repeatTime = 1;
    for(int i=curIdx-1;i>=0;i--){
        bool repeat = 0;
        //모음 연속인지 확인
        for(int j=0;j<5;j++){
            if(input[i]==vowel[j]){
                ++repeatTime;
                repeat = 1;
                break;
            }
        }
        if(!repeat) break;
    }
    return repeatTime>=3;
}
bool repeatCon3Time(int curIdx,string input){
    int repeatTime = 1;
    for(int i=curIdx-1;i>=0;i--){
        bool repeat = 1;
        //자음 연속인지 확인
        for(int j=0;j<5;j++){
            if(input[i]==vowel[j]){ //모음
                repeat = 0;
                break;
            }
        }
        //자음임을 확인
        if(repeat){
            ++repeatTime;
        }
        else break;
    }
    return repeatTime>=3;
}
bool repeatSameChar(int curIdx,string input){
    int repeatTime = 0;
    for(int i=curIdx-1;i>=0;i--){
        if(input[i] == input[curIdx])
            ++repeatTime;
        else
            break;
    }
    if(input[curIdx]=='o' || input[curIdx] == 'e' && repeatTime<3) return false;
    if(repeatTime==0) return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(true){
        string input;
        cin >> input;
        if(input=="end") break;
        bool hasVowel = 0;
        bool isRepeat3 = 0;
        bool isRepeatSame = 0;
        for(int i=0;i<input.length();i++){
            //모음 포함
            bool yn = isVowel(input[i]);
            //모음이면
            // cout << input[i] << " : ";
            if(yn){
                // cout <<"모음 ";
                hasVowel = true;
                //모음 3개 연속인지 확인
                repeatVowel3Time(i,input)==true?isRepeat3 = 1:0;
                // cout << "3개 연속 모음 여부 : " << repeatVowel3Time(i,input);
                //같은 글자 연속인지
                repeatSameChar(i,input)==true?isRepeatSame=true:0;
                // cout << "같은 글자 연속 여부 : " << repeatSameChar(i,input);
                
            }
            else{ //자음이면
                // cout <<"자음";
                //이전 문자열도 자음인지
                repeatCon3Time(i,input)==true?isRepeat3=1:0;
                //같은 글자 연속인지
                repeatSameChar(i,input)==true?isRepeatSame=true:0;
            }
            
        }
        if(!hasVowel || isRepeat3 || isRepeatSame){
            cout << "<" + input << ">" << " is not acceptable.";
        }
        else{
            cout << "<" + input << ">" << " is acceptable.";
        }
        cout <<"\n";
    }
    return 0;
}
//모음 포함
//모음/자음 각각 3개 연속 x
//같은 글자 연속 x (ee, oo는 허용)
