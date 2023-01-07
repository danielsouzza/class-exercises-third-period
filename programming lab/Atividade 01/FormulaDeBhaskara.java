import java.util.Scanner;

public class FormulaDeBhaskara {

    static Scanner input = new Scanner(System.in);
    public static void main(String[] args) {
      Double  a = input.nextDouble();
      Double  b = input.nextDouble();
      Double  c = input.nextDouble();
      Double delta = Math.pow(b,2) - (4*a*c);
  
      if(a == 0.0 || delta < 0){
        System.out.println("Impossivel calcular");
      }else{
        Double R1 = (-b + Math.sqrt(delta)) / (2*a);
        Double R2 = (-b - Math.sqrt(delta)) / (2*a);
        System.out.printf("R1 = %.5f\n",R1);
        System.out.printf("R2 = %.5f\n", R2);
      }
    }
}