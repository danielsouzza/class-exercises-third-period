import java.util.Scanner;

public class Quadrante {
    static Scanner input = new Scanner(System.in);
    public static void main(String[] args) {
        int x = input.nextInt();
        int y = input.nextInt();

        while (x != 0 || y != 0) {
            if(x > 0 && y > 0){
                System.out.println("primeiro");
            }else if(x < 0 && y > 0){
                System.out.println("segundo");
            }else if(x < 0 && y < 0){
                System.out.println("terceiro");
            }else{
                System.out.println("quarto");
            }
            x = input.nextInt();
            y = input.nextInt();
        }
    }
}
