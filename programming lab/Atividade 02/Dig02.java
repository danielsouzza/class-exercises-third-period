import java.util.Scanner;


public class Dig02 {

    static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        String nums = input.nextLine();
        System.out.println(digitCheck(nums));
    }

    static String digitCheck(String nums) {
        int digit = 10 - (somaOfdigits(nums) % 10);
        if (digit == 10)
            return "0";
        else
            return String.valueOf(digit);
    }

    static int somaOfdigits(String nums) {
        int soma = 0;
        int mult = 3;
        boolean startSum = false;
        int size = nums.length();
        

        for (int i = 0; i < size; i++) {
            int digit = Integer.valueOf(nums.substring(i, i + 1));
            if(digit > 0) startSum = true;

            if(startSum){
                soma +=  digit * mult;
                mult = (mult == 3) ? 1 : 3;
            }
            
        }
        return soma;
    }
}
