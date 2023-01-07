import java.util.Scanner;

public class NumeroPrimo {
    static Scanner input = new Scanner(System.in);
    public static void main(String[] args) {
        int num_input = input.nextInt();

        while (num_input-- > 0) {
            int num = input.nextInt();
            if(isPrimo(num)){
                System.out.println(num + " eh primo");
            }else{
                System.out.println(num + " nao eh primo");
            }
        }

    }

    static boolean isPrimo(int num){
        for(int i = 2; i < num;i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
}
