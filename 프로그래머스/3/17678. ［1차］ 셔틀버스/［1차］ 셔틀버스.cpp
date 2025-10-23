#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) { 
    //n번, t분 간격, 최대 m명
    string answer = "";
    
    sort(timetable.begin(),timetable.end());
    int hh = 9;
    int mm = 0;
    int cnt = 0;
    int idx = 0;
    int endCnt = -1; //탑승 끝난 셔틀 번호
    int endNum = 0; //마지막 자리 수
    int lastHH = 0; //마지막 탑승한 크루 도착시간
    int lastMM = 0;
    while(cnt<n){ //마지막 셔틀이면 끝남.
        int curNum = 0; //현재 탑승 인원
        for(;idx<timetable.size();idx++){
            if(curNum==m) break; //만석이면 break
            string timeStr = timetable[idx];
            int curH = stoi(timeStr.substr(0,2));
            int curM = stoi(timeStr.substr(3,2));
            //cout << curH << " " << curM << endl;
            if(curH<hh || (curH==hh && curM<=mm)){ 
                ++curNum;
                lastHH = curH; //마지막 크루 탑승 시간
                lastMM = curM;
                
                endCnt = cnt+1; //크루를 모두 보낸 버스 번호 기록
                endNum = curNum; //현재 셔틀 인원 기록
            }
            else{
                break;
            }
        }
        //cout << cnt << " " << cur_num << "\n";
        ++cnt; //셔틀 횟수
        if(cnt==n){ //다 못태웠을 수도 있음.
            break;
        }
        //다음 셔틀시간 계산
        mm+=t;
        hh+=mm/60;
        mm%=60;
    }
    //cout << endCnt << " " << hh << " " << mm << "\n";
    if(endCnt<n){ //이전에 다른 크루들을 모두 태우거나 아예 못태워서. 한자리 여유가 있으면, 마지막 셔틀시간
        //마지막 셔틀시간
        string hhStr = hh<10?"0"+to_string(hh):to_string(hh);
        string mmStr = mm<10?"0"+to_string(mm):to_string(mm);
        answer = hhStr + ":" + mmStr;
    }
    else if(endCnt==n){ //크루들을 다 태웠을 때
        if(endNum < m){ //자리가 남았을 때
            //마지막 셔틀시간
            string hhStr = hh<10?"0"+to_string(hh):to_string(hh);
            string mmStr = mm<10?"0"+to_string(mm):to_string(mm);
            answer = hhStr + ":" + mmStr;
        }
        else{ //자리가 찼을 때는 마지막 크루 도착시간보다 빨라야 함.
            int hhInt = lastHH;
            int mmInt = lastMM;
            mmInt-=1;
            if(mmInt<0){
                mmInt = 59;
                hhInt-=1;
            }
            string hhStr = hhInt<10?"0"+to_string(hhInt):to_string(hhInt);
            string mmStr = mmInt<10?"0"+to_string(mmInt):to_string(mmInt);
            answer = hhStr + ":" + mmStr;
        }
    }
    //cout <<endCnt << " " << n;
    //if(endCnt)
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