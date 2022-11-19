import java.util.Scanner;

public class SalarioComBonus {
    static Scanner input = new Scanner(System.in);
    public static void main(String[] args) {
        // String nome = input.nextLine();
        Double salario = input.nextDouble();
        Double montante = input.nextDouble();
        Double total = salario + (0.15*montante);

        System.out.printf("TOTAL = R$ %.2f",total);




    }
}
