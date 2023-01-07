import java.util.Scanner;

public class Dig01 {
    static Scanner input = new Scanner(System.in);
    public static void main(String[] args) { 
        String nums = input.nextLine();
        System.out.println(digitCheck(nums));
    }


    static String digitCheck(String nums){
        int digit = 10 - (somaOfdigits(nums) % 10);
        if (digit == 10) return "0";
        else return String.valueOf(digit);
    }

    static int somaOfdigits(String nums){
        int soma = 0;
        int mult = 3;
        int size = nums.length();

        for(int i = size-1; i >= 0; i--){
            soma += Integer.valueOf(nums.substring(i, i+1)) * mult;
            mult = (mult == 3) ? 1 : 3;
        }
        return soma;
    }
}