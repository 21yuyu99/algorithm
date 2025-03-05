#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    else{
        return a.first>b.first;
    }
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    //노래별 장르, 노래별 재생 횟수
    vector<int> answer;
    //장르별 횟수 합계 구하기. 내림차순 정렬
    //10^4 * log10^4(정렬)
    //10^4 * 4 = 완전 가능
    int genre_idx = 1;
    vector<pair<int,string>> gen_vector(1);
    map<string,int> gen_mapper;
    vector<vector<pair<int,int>>> gen_plays_vector(1);
    
    for(int i=0;i<plays.size();i++){
        int cur_idx = gen_mapper[genres[i]];
        if(cur_idx==0){
            cur_idx = genre_idx++;
            gen_vector.emplace_back();
            gen_plays_vector.emplace_back();
            gen_mapper[genres[i]] = cur_idx;
            gen_vector[cur_idx].second=genres[i];
        }
        gen_vector[cur_idx].first+= plays[i];
        gen_plays_vector[cur_idx].push_back({plays[i],i});
    }
    sort(gen_vector.begin(),gen_vector.end());
    
    //장르별 많이 재생된 노래
    for(int i=0;i<gen_plays_vector.size();i++){
        sort(gen_plays_vector[i].begin(),gen_plays_vector[i].end(),compare);
    }
    for(int i=gen_vector.size()-1;i>0;i--){
        int gen_idx = gen_mapper[gen_vector[i].second];
        int cnt = 0;
        for(int j=0;j<gen_plays_vector[gen_idx].size();j++){
            if(cnt==2) break;
            answer.push_back(gen_plays_vector[gen_idx][j].second);
            ++cnt;
        }
    }
    return answer; //베스트앨범(각 장르별 두 개)에 들어간 노래의 고유번호 순서대로
}
//주의!
//각 장르에 하나만 있을 수도 있다.

//수록 순서
//많이 재생된 장르
//(장르 내에) 많이 재생된 노래
//고유 번호가 낮은 노래

//노래 배열 10^4, 장르 개수는 10^2