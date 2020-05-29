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

public class Week5_Lab4 {
    public static void main(String[] args){
        int num=0;
        Scanner input = new Scanner(System.in);
        
        System.out.print("Please enter a number: ");
        num = input.nextInt();
        
        while(num<1 || num>10){
            System.out.println("Oops, the number should be in range of 1 to 10!!");
            System.out.print("Please enter a number:");
            num = input.nextInt();
        }
        
        for(int i=1;i<=num;i++){
            System.out.println(i);
        }
    }
}
