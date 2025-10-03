#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
//infix로 탐색필요.
//앞으로의 0은 맨 왼쪽에만 추가가 가능하다.
//포화이진트리 개수는 2^n-1
bool checkNode(long left,long right,string tmp){
    long root = (left+right)/2;
    if(left >= right) return true;
    if((tmp[(left+root-1)/2]=='1' || tmp[(root+1+right)/2]=='1') && tmp[root]=='0') return false;
    else{
        return checkNode(left,root-1,tmp) 
            && checkNode(root+1,right,tmp);
    }
} 
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(int i=0;i<numbers.size();i++){
        //이진수로 변환
        long n =  numbers[i];
        string tmp = "";
        while(n>0){
            tmp = to_string(n%2) + tmp;
            n/=2;
        }
        //포화이진트리 만들기
        long cnt = 1;
        int h = 1;
        while(cnt<tmp.length()){
            ++h;
            cnt = pow(2,h)-1;
        }
        while(cnt>tmp.length()){
            tmp = "0" + tmp;
        }
        //cout << numbers[i] << " " << tmp << "\n";
        checkNode(0,tmp.length()-1,tmp)?answer.push_back(1):answer.push_back(0);
    }
    return answer;
}

//42(10101) = 5글자 5/2 = 2 ... 1
//         *
//    *        *
//  0    0    0  0


//5(101)는 왜 안되는지?? - 포화이진트리여야해서 == 0101000 = 8 + 32 = 40
//         *
//    *      0  
//  0    0  0  0  

//8
//0001000 len 7


//         7
//    3          11
//  1    5    9     13
//0   2 4 6  8 10 12  14 

//h가 3이면 -2부터 시작
//h가 4면 -4부터 시작?

