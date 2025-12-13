import java.util.*;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for(int cmd=0;cmd<commands.length;cmd++){
            int i = commands[cmd][0]-1;
            int j = commands[cmd][1]-1;
            int k = commands[cmd][2]-1;
            int[] tmpArray = new int[j-i+1];
            //System.out.println(tmpArray.length-1+i);
            for(int idx = 0;idx<tmpArray.length;idx++){
                tmpArray[idx] = array[idx+i]; 
            }
            Arrays.sort(tmpArray);
            answer[cmd] = tmpArray[k];
        }
        return answer;
    }
}