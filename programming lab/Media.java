import java.util.Scanner;

public class Media {
    static Scanner input = new Scanner(System.in);
    public static void main(String[] args) {
        Double a = input.nextDouble()*2;
        Double b = input.nextDouble()*3;
        Double c = input.nextDouble()*5;

        Double media = (a+b+c)/10;

        System.out.printf("MEDIA = %.1f",media);

    }
}
