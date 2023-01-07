import java.util.Scanner;

public class Dig03 {
    static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        String literal = input.nextLine();
        String digitis = literal.replaceAll("\\D", "");
        System.out.println(digitCheck(digitis));
    }

    static String digitCheck(String nums) {
        int digit = 10 - (somaOfdigits(nums) % 10);
        return String.valueOf(digit);
    }

    static int somaOfdigits(String nums) {
        int soma = 0;
        int mult = 4;
        int size = nums.length();
        

        for (int i = size-1; i >= 0; i--) {
            int digit = Integer.valueOf(nums.substring(i, i + 1));
            soma +=  digit * mult;
            mult = (i % 2 == 0) ? 9 : 4;
        }
        return soma;
    }
}
