import java.util.Scanner;

public class GastoDeCombustível {
    static Scanner input = new Scanner(System.in);
    public static void main(String[] args) {
        Double time = input.nextDouble();
        Double speed = input.nextDouble();
        Double litros = (time * speed) / 12;
        System.out.printf("%.3f\n",litros); 
    }
}
