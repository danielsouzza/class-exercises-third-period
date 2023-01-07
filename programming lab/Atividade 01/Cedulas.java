
import java.util.Scanner;

public class Cedulas {
    static Scanner input = new Scanner(System.in);
    public static void main(String[] args) {
        int value = input.nextInt();
        int[] cedulas = {100,50,20,10,5,2,1};
        int[] result = new int[7];
        int aux = value;

        for (int i = 0;i < 7;i++) {
            result[i] = aux/cedulas[i];
            aux = aux % cedulas[i];
        }
        System.out.printf("%d\n",value);
        for (int i = 0;i < 7;i++) {
            System.out.printf("%d nota(s) de R$ %d,00\n",result[i],cedulas[i]);
        }
    }
}