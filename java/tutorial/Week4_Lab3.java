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

public class Week4_Lab3 {
    public static void main(String[] args){
        int celsius = 0;
        Scanner input = new Scanner(System.in);
        System.out.println("Please enter the value of celsius :");
        celsius = input.nextInt();
        
        if(celsius<10)
            System.out.println("Is is cold!");
        else if(celsius>22)
            System.out.println("Is is hot!!");
        else
            System.out.println("It is normal temperature.");
    }
}
