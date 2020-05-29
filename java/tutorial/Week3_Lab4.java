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

public class Week3_Lab4 {
    public static void main(String args[]){
        //Create keyboard stream
        Scanner keyboard = new Scanner(System.in);
        double fahrenheit = 0.0, celcius=0.0;
        
        System.out.print("Please enter the value of fahrenheit :");
        fahrenheit = keyboard.nextDouble();
        
        celcius = 5.0/9.0 *(fahrenheit-32.0);
        System.out.printf("%d F = %d C\n",Math.round(fahrenheit),Math.round(celcius));
    }
}
