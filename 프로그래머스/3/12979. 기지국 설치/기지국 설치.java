import java.util.*;
import java.lang.*;
class Solution {
    public int solution(int n, int[] stations, int w) { //아파트 개수,기지국 설치된 번호 배열, 전파 도달 거리 
        int complete_idx = 0;
        int max_distance = w*2+1;
        int answer=0;
        for(int i=0;i<stations.length;i++){
            int idx = stations[i];
            int s = Math.max(idx-w,0)-1; //현재 기지국이 전달되지 않는 왼쪽 거리
            //System.out.println(s);
            if(s>complete_idx){
                int distance = s - complete_idx;
                answer += distance/max_distance;
                if(distance%max_distance!=0){
                    ++answer;
                }
            }
            complete_idx = idx+w;
        }
        if(complete_idx<n){
            int distance = n-complete_idx;
            answer += distance/max_distance;
            if(distance%max_distance!=0){
                ++answer;
            }
        }
        return answer;
    }
}
//전달 안되는 가장 왼쪽값과 오른쪽 값을 알아야 함.

//양쪽으로 w만큼 전달
//최소 설치하여 모두 전달
// n : 2*10^8 (아파트번호는 1번부터)
//stations length: 10^4(오름차순 정렬.)
//w : 10^4
// O(1)

//w 기준이면 좋을 듯

//1.
//stations에서 설치되있는 곳 visited 1로 설정

//2.
//for문 n 어디에 필요한지 넣기.
//전달 안되는 현재 가장 왼쪽 부분부터 넣고 + w*2 이후 다시 확인
//
