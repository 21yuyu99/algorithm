#include <iostream>
using namespace std;
int parant[1000001] = {0,};
int Find(int a){
    if(parant[a]==a)
        return a;
    return parant[a] = Find(parant[a]);
}
void Union(int a,int b){
    int pA = Find(a);
    int pB = Find(b);
    if(pA<pB){
        parant[pB] = pA;
    }
    else{
        parant[pA] = pB;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,M;    
    cin >> N >> M;
    for(int i=0;i<=N;i++){
        parant[i] = i;
    }
    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a==0){ //합집합 만들기
            Union(b,c);
        }
        else{ 
            int pB = Find(b);
            int pC = Find(c);
            if(pB==pC){
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
    }
    return 0;
}