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

public class Week4_Lab2 {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int no1=0,no2=0;
        System.out.println("Please enter 2 integer value:");
        no1 = input.nextInt();
        no2 = input.nextInt();
        System.out.printf("Before change: no1 : %4d , no2 : %4d\n",no1,no2);
        int temp = no1;
        no1 = no2;
        no2 = temp;
        System.out.printf("After change: no1: %4d , no2: %4d\n",no1,no2);
    }
}
