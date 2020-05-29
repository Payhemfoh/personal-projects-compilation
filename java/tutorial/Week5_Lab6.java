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

public class Week5_Lab6 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Please enter a word: ");
        String input = sc.nextLine();
        
        for(int i=0;i<input.length();i++){
            System.out.println(input.charAt(i));
        }
    }
}
