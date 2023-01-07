import java.util.Scanner;

public class Tabuada {
    static Scanner input = new Scanner(System.in);
    public static void main(String[] args) {
        int num = input.nextInt();

        for (int i = 1; i < 11; i++) {
            System.out.printf("%d x %d = %d\n",i,num,(i*num));
        }
    }
}
