/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Payhemfoh
 */
import java.util.Scanner;
public class Week5_Lab7 {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Please enter a sentence");
        String sentence = sc.nextLine();
        int vowel=0,space=0,consonent=0;
        sentence = sentence.toLowerCase();
        for(int i=0;i<sentence.length();i++){
            switch(sentence.charAt(i)){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowel++;
                    break;
                case ' ':
                    space++;
                    break;
                default:
                    consonent++;
            }//end switch
        }
        System.out.printf("Vowel: %d\nSpace:%d\nConsonent:%d\n", vowel,space,consonent);
    }//end main
}//end class
