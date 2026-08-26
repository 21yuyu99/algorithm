#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
int N,T;
vector<vector<int>> F; //신봉음식 //비트마스크 001(1) 010(2) 100(4)
vector<vector<int>> B; //신앙심
vector<vector<int>> Attack; //이번회차에 전파당했는지
vector<vector<int>> Visited;
int dr[4] = {-1,1,0,0}; //위,아래,왼,오
int dc[4] = {0,0,-1,1};
struct Group{
    int LR;
    int LC;
    vector<pair<int,int>> member; //대표자 포함 value = (R,C)
};
vector<Group> Groups[3];
void Input(){
    cin >> N >> T;

    B.resize(N,vector<int>(N,0));
    F.resize(N,vector<int>(N,0));
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<N;j++){
            if(s[j]=='T'){
                F[i][j] = 1;
            }
            else if(s[j]=='C'){
                F[i][j] = 2;
            }
            else{
                F[i][j] = 4;
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> B[i][j];
        }
    }
}

void Morning(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            B[i][j]+=1;
        }
    }
}
int Check_Three_Group(int r,int c){
    int num = F[r][c];
    int cnt = 0;
    for(int i=0;i<3;i++){
        if(num&1)
            cnt++;
        num>>=1;
    }
    return cnt-1;
}
bool check_bound(int r,int c){
    if(r<0 || c < 0 || r>=N || c >= N) return false;
    return true;
}
void Dfs(int r,int c,int bidx,int sidx){
    for(int d=0;d<4;d++){
        int tr = r + dr[d];
        int tc = c + dc[d];
        if(!check_bound(tr,tc)) continue;
        if(Visited[tr][tc]) continue;
        if(F[r][c]!=F[tr][tc]) continue;
        Visited[tr][tc] = 1;
        Groups[bidx][sidx].member.push_back({tr,tc});
        Dfs(tr,tc,bidx,sidx);
    }
}
void find_leader(int bidx,int sidx){
    int lr = 55;
    int lc = 55;
    int lb = -1;
    const vector<pair<int,int>> &mem = Groups[bidx][sidx].member;
    for(int i=0;i<mem.size();i++){
        int r = mem[i].first;
        int c = mem[i].second;
        if(make_tuple(B[r][c],-r,-c) >= make_tuple(lb,-lr,-lc)){
            //cout << lb << " " << lr << " " << lc << " " << B[r][c] << " " << r << " " << c << "\n";
            lb = B[r][c];
            lr = r;
            lc = c;
        }
    }
    Groups[bidx][sidx].LR = lr;
    Groups[bidx][sidx].LC = lc;
    B[lr][lc] += mem.size()-1;
    for(int i=0;i<mem.size();i++){
        int r = mem[i].first;
        int c = mem[i].second;
        if(r == lr && c == lc) continue;
        B[r][c]-=1;
    }
}
void print_group(){
    for(int i=0;i<3;i++){
        cout << "group num: " << i << "\n";
        for(int j=0;j<Groups[i].size();j++){
            cout << " j : " << j << " leader : " << Groups[i][j].LR << " " << Groups[i][j].LC << "\n";
            for(int t=0;t<Groups[i][j].member.size();t++){
                cout << Groups[i][j].member[t].first << " " << Groups[i][j].member[t].second << " " 
                << B[Groups[i][j].member[t].first][Groups[i][j].member[t].second] << "\n";
            }
        }
    }
}
void print_B(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << B[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
bool compare(Group &a,Group &b){
    return (B[a.LR][a.LC] > B[b.LR][b.LC]) || (B[a.LR][a.LC] == B[b.LR][b.LC] && a.LR < b.LR) || (B[a.LR][a.LC] == B[b.LR][b.LC] && a.LR ==  b.LR && a.LC < b.LC);
}
void print_F(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(F[i][j]&1)
                cout << 'T';
            if(F[i][j]&2)
                cout << 'C';
            if(F[i][j]&4)
                cout << 'M';
            cout << " ";
        }
        cout << "\n";
    }
}
void propagate(int bidx,int sidx){
    int lr = Groups[bidx][sidx].LR;
    int lc = Groups[bidx][sidx].LC;
    int lb = B[lr][lc];
    int x = lb-1;
    int d = lb%4;
    B[lr][lc] = 1;
    int tr = lr;
    int tc = lc;
    while(x>0){
        tr += dr[d];
        tc += dc[d];
        if(!check_bound(tr,tc)) return;
        if(F[lr][lc]==F[tr][tc]) continue;
        int &y = B[tr][tc];
        Attack[tr][tc] = 1;
        if(x>y){ //강한전파
            F[tr][tc] = F[lr][lc];
            x -= y+1;
            y+=1;
        }
        else{ //약한전파
            F[tr][tc]|=F[lr][lc];
            y+=x;
            x = 0;
        }
    }
}
void output(){
    int total[7] = {0,};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            total[F[i][j]-1] += B[i][j];
        }
    }        
        cout << total[6] << " ";
        cout << total[2] << " ";
        cout << total[4] << " ";
        cout << total[5] << " ";
        cout << total[3] << " ";
        cout << total[1] << " ";
        cout << total[0] << " ";
    cout << "\n";
}
int main() {
    Input();
    //cout <<"----start---\n";
    //print_B();
    for(int t=0;t<T;t++){
        Visited.clear();
        Visited.resize(N,vector<int>(N,0));
        Attack.clear();
        Attack.resize(N,vector<int>(N,0));
        for(int i=0;i<3;i++){
            Groups[i].clear();
        }
        Morning();
        //cout <<"----morning end---\n";
        //print_B();
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(Visited[i][j]) continue;
                Visited[i][j] = true;
                int group_i = Check_Three_Group(i,j);
                Group g;
                g.member.push_back({i,j});
                Groups[group_i].push_back(g);
                Dfs(i,j,group_i,Groups[group_i].size()-1); //group 만들기
                find_leader(group_i,Groups[group_i].size()-1);
            }
        }
        //cout << "----lunch end----\n";
        //print_group();
        for(int i=0;i<3;i++){
            sort(Groups[i].begin(),Groups[i].end(),compare);
        }
        //cout << "----sort end----\n";
        //print_group();

        for(int i=0;i<3;i++){
            for(int j=0;j<Groups[i].size();j++){
                if(Attack[Groups[i][j].LR][Groups[i][j].LC]) continue;
                //cout << Groups[i][j].LR << " " << Groups[i][j].LC << "\n";
                propagate(i,j);
                //print_B();
            }
        }
        //print_F();
        output();
    }
    //********
    //T end 
    //********
    return 0;
}
//세 그룹 나열


//** 음식 합치기
//** 그룹 변화