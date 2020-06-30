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

public class Week6_Lab7 {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Please enter the sentence:");
        String text = sc.nextLine();
        maniString(text);
    }
    
    /**
     * This program manipulate the given string by Capitalize and remove space
     * @param text given string
     */
    public static void maniString(String text)
    {
        String sentence = "";
        for( int i=0;i<text.length();i++){
            if(text.charAt(i)==' '){
                sentence = sentence + text.toUpperCase().charAt(++i);
            
            }else{
                sentence+=text.charAt(i);
            }
        }
        System.out.println("Result: "+sentence);
    }
}
