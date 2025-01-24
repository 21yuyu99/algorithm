#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <climits>
using namespace std;
int maximum = INT_MIN;
int minimum = INT_MAX;
vector<int> num;
vector<int> oper(4,0);
vector<int> tmp_oper;
int N;
void find(int idx,int para_num){
    for(int j=0;j<4;j++){
        int tmp = para_num;
        if(tmp_oper[j]!=0){
            if(j==0){
                tmp+=num[idx];
            }
            else if(j==1){
                tmp-=num[idx];
            }
            else if(j==2){
                tmp*=num[idx];
            }
            else{
                tmp/=num[idx];
            }
            --tmp_oper[j];
            find(idx+1,tmp);
            ++tmp_oper[j];
        }
    }
    if(idx==N){
        maximum = max(maximum,para_num);
        minimum = min(minimum,para_num);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    num.resize(N);
    for(int i=0;i<N;i++){
        cin >> num[i];
    }
    for(int i=0;i<4;i++){
        cin >> oper[i];
    }
    tmp_oper = oper;
    find(1,num[0]);
    cout << maximum << "\n" << minimum;
    return 0;
}