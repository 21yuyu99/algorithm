import java.util.*;
class Solution {
    int[] Numbers;
    int Target;
    int answer = 0;
    public int solution(int[] numbers, int target) {
        Numbers = numbers;
        Target = target;
        dfs(0,0);
        return answer;
    }
    
    public void dfs(int idx,int num){
        if(idx>=Numbers.length){
            if(num==Target){
                ++answer;   
            }
            return;
        }
        dfs(idx+1,num+Numbers[idx]);
        dfs(idx+1,num-Numbers[idx]);
    }
}