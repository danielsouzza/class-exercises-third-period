import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Dig04 {
    static Scanner input = new Scanner(System.in);
    public static void main(String[] args) { 
        String nums = input.nextLine();
        System.out.println(decode(nums));
    }



    static String decode(String code){
        Map<Character,Integer> symbols = creatorSymbols();
        char[] codeChar = code.toCharArray();
        String newCode = "";
        int soma = 0;
        String dv;
        for(int i = 0; i < code.length();i++){
            if(Character.isDigit(codeChar[i])){
                soma += Character.getNumericValue(codeChar[i]);
            }else{
                soma += Integer.valueOf(symbols.get(codeChar[i]));            }
        }
        int resto = 16 - (soma % 16);
        if(resto <= 9){
            dv = String.valueOf(resto);
        }else{
            dv = String.valueOf(getKey(resto));
        }
        newCode = code.substring(0, code.length()-1) + dv + code.substring(code.length()-1);
        return newCode;

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
        symbols.put('-', 10);
        symbols.put('$', 11);
        symbols.put(':', 12);
        symbols.put('/', 13);
        symbols.put('.', 14);
        symbols.put('+', 15);
        symbols.put('A', 16);
        symbols.put('B', 17);
        symbols.put('C', 18);
        symbols.put('D', 19);
        return symbols;
    }
}