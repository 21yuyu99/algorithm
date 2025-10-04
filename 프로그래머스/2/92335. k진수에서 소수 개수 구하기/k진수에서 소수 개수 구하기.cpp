#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
bool isPrime(long num){
    if(num==1) return false;
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0) return false;
    }
    return true;
}

int solution(int n, int k) {
    string s_n = "";
    //n = 1000000;
    //k = 3;
    while(n>0){
        s_n = to_string(n%k) + s_n;
        n/=k;
    }
    //cout << s_n << " ";
    string tmp = "";
    int answer = 0;
    for(int i=0;i<s_n.length();i++){
        if(s_n[i] =='0'){
            if(tmp.length()>0){
                answer+=isPrime(stol(tmp));
                //cout << tmp << " " << isPrime(stoi(tmp)) << endl;
            }
            tmp = "";
        }
        else{ 
            tmp += s_n[i];
        }
    }
    if(tmp.length()>0){
            //cout << tmp << " " << isPrime(stoi(tmp)) << endl;
            answer+=isPrime(stol(tmp));
    }
    return answer;
}
//n -> k진수로 변환
//다음과 같은 소수 몇 개?
//p는 0을 포함하지 않음
//0p0
//p0
//0p
//p

//for문으로 돌면서 0이 되기 전까지 찾기? 그래야 조건에 만족함.

//211020101011
//조건에 맞는 **소수**(10진법으로 보았을 때 소수여야 함)
//211 2 11

//1은 소수가 아님 주의
//즉 소수이고, 중간에 0이 안들어가면 됨

//n은 10^6
