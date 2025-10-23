#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int toMin(string time){
    return stoi(time.substr(0,2))*60 + stoi(time.substr(3,2));
}
string toStr(int time){
    int hh = time/60;
    int mm = time%60;
    string hhStr = hh<10?"0"+to_string(hh):to_string(hh);
    string mmStr = mm<10?"0"+to_string(mm):to_string(mm);
    return hhStr + ":" + mmStr;
}
string solution(int n, int t, int m, vector<string> timetable) { 
    //n번, t분 간격, 최대 m명
    string answer = "";
    sort(timetable.begin(),timetable.end());
    vector<int> timetableInt;
    for(auto x:timetable){ timetableInt.push_back(toMin(x)); };
    int idx = 0;
    int curCnt = 0; // 현재 인원
    int curTime = 540;
    for(int i=1;i<=n;i++){
        curCnt = 0;
        //cout << timetableInt[idx] << " " << curTime << "\n";
        while(idx<timetableInt.size() && curCnt<m && curTime>=timetableInt[idx]){
            ++curCnt;
            ++idx;
        }
        if(i==n) break;
        curTime+=t;
    }
    if(curCnt==m){ //인원 초과했을 때
        int lastM = timetableInt[idx-1];
        int answerM = lastM-1;
        answer = toStr(answerM);
    }
    else{
        answer = toStr(curTime);
    }
   
    return answer; //제일 늦은 도착 시간
}
//콘은 같은 시간 도착한 사람 중 가장 뒤에 선다.

//timetable.size()<=2000
//크루의 정류장 도착시간 00:01~23:59
//콘의 도착 시간 00:00~23:59

//09:00부터 출발 

//09:00(08:00, 08:01, 08:02, 08:03)

//09:00(08:00). 09:10(09:09, 09:10) 답 : 09:09

//09:00(09:00 09:00) 09:01(09:00 09:00) 댭 : 08:59

//09:00(00:01 00:01 00:01 00:01 00:01) 답 : 00:00

//09:00....(23:59)???

//다음날의 23:59에 돌아간다.

//모든 애들을 태워보고 가장 늦게 탑승하는 애 시간. 현재 셔틀의 시간을 알면 될 듯.


//셔틀 끝까지 계산해보고.

//콘이 타면 못타는 애가 있다. 그러면 마지막 애 시간 -1분이 답
//콘이 타도 다 탈 수 있다. 그러면 셔틀 시간이 답.
//다 타도 셔틀이 남는다. 그러면 마지막 셔틀시간이 답