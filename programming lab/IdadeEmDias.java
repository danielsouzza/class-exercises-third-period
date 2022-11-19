import java.util.Scanner;

public class IdadeEmDias {
    static Scanner input = new Scanner(System.in);
    public static void main(String[] args) {
        int idade = input.nextInt();
        int ano = idade / 365;
        idade = idade % 365;
        int mes = idade / 30;
        int dia = idade % 30;

        System.out.println(ano + " ano(s)");
        System.out.println(mes + " mes(es)");
        System.out.println(dia + " dia(s)");
    }
}
