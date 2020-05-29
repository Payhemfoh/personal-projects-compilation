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

public class Week5_Lab2 {
    public static void main(String[] args){
        int input=0;
        int total=0;
        int count=0;
        double average = 0.0;
        Scanner sc = new Scanner(System.in);
        do{
            System.out.print("Please enter a number:");
            input = sc.nextInt();
            total+=input;
            count++;
        }while(input!=0);
        
        average = (float)total/--count;
        
        System.out.printf("The total is %d\n The average is %f\n\n", total,average);
        
        input = 1 ; count = 0; total =0;
        
        System.out.print("Please enter a number:");
        input = sc.nextInt();
        while(input!=0){
            total+=input;
            count++;
            System.out.print("Please enter a number:");
            input = sc.nextInt();
        }
        
        average = (double)total/count;
        
        System.out.printf("The total is %d\n The average is %f\n\n", total,average);
    }
}
