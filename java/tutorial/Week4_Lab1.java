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

public class Week4_Lab1 {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int no1=0,no2=0;
        
        System.out.println("Please enter the first number :");
        no1 =input.nextInt();
        System.out.println("Please enter the second number :");
        no2 = input.nextInt();
        
        if(no1>no2){
            System.out.printf("no1 : %-5d > no2: %-5d\n",no1,no2);
        }
        else if(no1<no2)
            System.out.printf("no1 : %-5d < no2 : %-5d\n",no1,no2);
        else
            System.out.printf("no1 : %-5d = no2 : %-5d\n",no1,no2);
    }
}
