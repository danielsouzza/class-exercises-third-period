import java.util.Scanner;

public class ParOuImpar {
    static Scanner input = new Scanner(System.in);
    public static void main(String[] args) {
        int num = input.nextInt();

        while (num-- > 0) {
            int tamp = input.nextInt();
            if(tamp == 0){
                System.out.println("NULL");
            }else if(tamp % 2 == 0){
                if(tamp > 0){
                    System.out.println("EVEN POSITIVE");
                }else{
                    System.out.println("EVEN NEGATIVE");
                }
            }else{
                if(tamp > 0){
                    System.out.println("ODD POSITIVE");
                }else{
                    System.out.println("ODD NEGATIVE");
                }
            }

        }
    }
}
