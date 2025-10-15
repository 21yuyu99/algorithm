import java.util.*;
class Solution {
    public String solution(String s) {
        String tmp[] = s.split(" ");
        int num[] = new int[tmp.length];
        for(int i=0;i<num.length;i++){
            num[i] = Integer.parseInt(tmp[i]);
        }
        int min_num = Integer.MAX_VALUE;
        int max_num = Integer.MIN_VALUE;
        
        for(int i=0;i<num.length;i++){
            min_num = Math.min(min_num,num[i]);
            max_num = Math.max(max_num,num[i]);
        }
        
        String answer = "";
        answer += Integer.toString(min_num) + " " + Integer.toString(max_num);
        return answer;
    }
}