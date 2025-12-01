#include <iostream>
#include <vector>
using namespace std;
pair<int,int> check_cnt(string s){
    int o_cnt = 0;
    int x_cnt = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='O'){
            ++o_cnt;
        }
        else if(s[i]=='X'){
            ++x_cnt;
        }
    }
    return{x_cnt,o_cnt};
}
int check_success(string s,char c){
    int success_cnt = 0;
    bool currentSuccess = true;
    //세로 확인
    for(int i=0;i<3;i++){
        currentSuccess = true;
        for(int j=i;j<9;j+=3){
            if(s[j]!= c){
                currentSuccess = false;
                break;
            }
        }
        if(currentSuccess){
            ++success_cnt;
        }
    }

    //가로 확인
    for(int i=0;i<9;i+=3){
        currentSuccess = true;
        for(int j=0;j<3;j++){
            if(s[i+j]!= c){
                currentSuccess = false;
                break;
            }            
        }
        if(currentSuccess){
            ++success_cnt;
        }        
    }

    //왼쪽 시작 대각선
    currentSuccess = true;
    for(int i=0;i<9;i+=4){
        if(s[i]!= c){
            currentSuccess = false;
            break;
        }   
    }
    if(currentSuccess){
        ++success_cnt;
    }      
    
    //오른쪽 시작 대각선
    currentSuccess = true;
    for(int i=2;i<8;i+=2){
        if(s[i]!= c){
            currentSuccess = false;
            break;
        }         
    }
    if(currentSuccess){
        ++success_cnt;    
    }  

    return success_cnt;;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(true){
        string input;
        cin >> input;
        if(input=="end") break;
        pair<int,int> cnt = check_cnt(input); //{x,y}
        if(!(cnt.second == cnt.first || cnt.first-cnt.second==1)) { //O가 더 많을 수 없음.
            cout << "invalid\n";
            continue;
        }
        // if(cnt.second==4 && cnt.first==5){ //게임판이 가득 참
        //     cout << "valid\n";
        //     continue;
        // }
        int xSuccess = check_success(input,'X'); //X 성공했는지 확인
        int ySuccess = check_success(input,'O'); //O 성공했는지 확인
        //cout << xSuccess << " " << ySuccess << "\n";
        if((xSuccess<=0 && ySuccess<=0) && !(cnt.second==4 && cnt.first==5)){ //가득차지 않았는데, 성공한 것이 없으면 
            cout << "invalid\n";
            continue;
        }
        
        if(xSuccess >0 &&  ySuccess > 0){ //둘 다 성공할 수는 없음.
            cout << "invalid\n";
            continue;
        }

        // if(xSuccess > 1 || ySuccess > 1){ //성공한 것이 여러개일 수 없음.
        //     cout << "invalid\n";
        //     continue;
        // }        
        if(xSuccess > 0 && cnt.first <= cnt.second){
            cout << "invalid\n";
            continue;
        }
        if(ySuccess > 0 && cnt.second != cnt.first){
            cout << "invalid\n";
            continue;
        }
        cout << "valid\n";

    }
    return 0;
}