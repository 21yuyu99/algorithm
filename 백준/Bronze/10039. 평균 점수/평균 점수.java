import java.util.Scanner;

import static java.lang.Math.max;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int score = 0;
        for(int i=0;i<5;i++){
            int input = sc.nextInt();
            input = max(input,40);
            score += input;
        }
        System.out.print(score/5);
    }
}