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

public class Week5_Lab5 {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int num = 0;
        
        System.out.print("Please enter a number (2 - 10): ");
        num = input.nextInt();
        
        while(num<2 || num>10){
            System.out.println("The number should in range of 2 to 10");
            System.out.print("Please enter a number (2 - 10): ");
            num = input.nextInt();
        }
        
        for(int i=1;i<=num;i++){
            System.out.print(i+"\t");
            for(int j=0;j<i;j++){
                System.out.print("*");
            }
            System.out.print("\n");
        }
        for(int i=num-1;i>0;i--){
            System.out.print(i+"\t");
            for(int j=0;j<i;j++){
                System.out.print("*");
            }
            System.out.print("\n");
        }
    }
}
