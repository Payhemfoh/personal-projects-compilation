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
public class Week4_Lab4 {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int num1=0,num2=0,num3=0;
        
        //get the inputs
        System.out.println("Please enter the first decimal value:");
        num1 = input.nextInt();
        
        System.out.println("Please enter the second decimal value:");
        num2 = input.nextInt();
        
        System.out.println("Please enter the third decimal value:");
        num3 = input.nextInt();
        
        int max=0,min=0,median=0;
        /*
        if (num1 > num2){
            if(num3>num1){
                max =num3;
                min = num2;
                median = num1;
            }
            else{
                min = num1;
                if(num3>num2){
                    min=num2;
                    median=num3;
                }else{
                    min=num3;
                    median=num2;
                }
            }
        }
        //num2>num1
        else{
            if(num3>num2){
                max=num3;
                median=num2;
                min=num1;
            }else{
                max=num2;
                if(num3>num1){
                    median=num3;
                    min=num1;
                }else{
                    median=num1;
                    min=num3;
                }
            }
        }
        */
        if (num1>num2){
            max = num1;
            min = num2;
        }else{
            max = num2;
            min = num1;
        }
        
        if(num3>max){
            median = max;
            max = num3;
        }else{
            if(num3<min){
                median = min;
                min = num3;
            }else{
                median = num3;
            }
        }
        
        System.out.printf("%d < %d < %d\n",min,median,max);
        System.out.printf("%d > %d > %d\n", max, median, min);
    }
}
