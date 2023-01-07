import java.util.Scanner;

public class Divisores {
    static Scanner input = new Scanner(System.in);
    public static void main(String[] args){
        int value = input.nextInt();
        for(int i = 1; i <= value; i++){
            if(value % i == 0){
                System.out.println(i);
            }
        }
    }
}