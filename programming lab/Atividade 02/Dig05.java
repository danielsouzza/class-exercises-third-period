import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Dig05 {
    static Scanner input = new Scanner(System.in);
    public static void main(String[] args) { 
        String nums = input.nextLine();
        System.out.println(decode(nums));
    }



    static String decode(String code){
        Map<Character,Integer> symbols = creatorSymbols();
        char[] codeChar = code.toCharArray();
        int soma = 0;
        String dv;
        int resto;
        for(int i = 0; i < codeChar.length;i++){

            if(Character.isDigit(codeChar[i])){
                soma += Character.getNumericValue(codeChar[i]);
            }else if(codeChar[i] >= 65  && codeChar[i] <= 90){
                soma += codeChar[i] - 55;
            }else{
                soma += Integer.valueOf(symbols.get(codeChar[i]));
            }
        }
        

        resto = (soma % 43);

        if(resto <= 9){
            dv = String.valueOf(resto);
        }else if(resto >= 36 && resto <= 42){
            dv = String.valueOf(getKey(resto));
        }else{
            dv = String.valueOf((char)(resto+55));
        }
        return dv;

    }

    static Character getKey(int i){
        Map<Character,Integer> symbols = creatorSymbols();
        Set<Character> keys = symbols.keySet();
        Character item = '0';
        for (Character character : keys) {
            if(i == symbols.get(character) ){
                item = character;
            }
        }
        return item;
    }

    static Map<Character,Integer> creatorSymbols(){
        Map<Character,Integer> symbols = new HashMap<Character,Integer>();
        symbols.put('-', 36);
        symbols.put('.', 37);
        symbols.put(':', 38);
        symbols.put('$', 39);
        symbols.put('/', 40);
        symbols.put('+', 41);
        symbols.put('%', 42);
        return symbols;
    }
}
