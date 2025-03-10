import java.util.ArrayList;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N,M;
        N = sc.nextInt();
        M = sc.nextInt();
        ArrayList<Integer> box_arr = new ArrayList<>(N);
        for(int i=0;i<N;i++){
            box_arr.add(0);
        }
        for(int m=0;m<M;m++){
            int i,j,k;
            i = sc.nextInt();
            j = sc.nextInt();
            k = sc.nextInt();
            for(int idx=i-1;idx<j;idx++){
                box_arr.set(idx,k);
            }
        }
        for(int i=0;i<N;i++){
            System.out.print(box_arr.get(i)+" ");
        }
    }
}