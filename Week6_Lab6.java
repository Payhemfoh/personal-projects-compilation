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
public class Week6_Lab6 {
    public static void main(String[] args)
    {
        int option=0;
        char yesNo='Y';
        
        do{
        menu();
        option = getInteger("Your choice:");
        processOption(option);
        
        yesNo = nextCalculation("\nDo you want to continue[Y/N]");
        }while(yesNo=='Y');
    }
    
    /**
     * This method convert celcius to fahrenheit
     * @param celcius
     * @return fahrenheit
     */
    public static double cToF(double celcius)
    {
        double fahrenheit = celcius * (5.0/9.0) + 32;
        return fahrenheit;
    }
    
    /**
     * This method convert fahrenheit to celcius
     * @param fahrenheit
     * @return celcius
     */
    public static double fToC(double fahrenheit)
    {
        double celcius = (fahrenheit - 32) * (9.0/5.0);
        return celcius;
    }
    
    /**
     * This method display the main menu
     */
    public static void menu()
    {
        System.out.println("1->Celcius to Fahrenheit");
        System.out.println("2->Fahrenheit to Celcius");
        System.out.println("3->Exit");
    }
    
    /**
     * This method get integer input from user
     * @param text prompt text
     * @return option the input of user
     */
    public static int getInteger(String text)
    {
        Scanner sc=new Scanner(System.in);
        int option=0;
        System.out.print(text);
        option = sc.nextInt();
        return option;
    }
    
    /**
     * This method get double input from user
     * @param text prompt text
     * @return option the input of user
     */
    public static double getDouble(String text)
    {
        Scanner sc=new Scanner(System.in);
        double option=0;
        System.out.print(text);
        option = sc.nextDouble();
        return option;
    }
    
    /**
     * This method contain the main process of the program
     * @param option the choice of user from main menu
     */
    public static void processOption(int option)
    {
        double input=0.0,answer=0.0;
        switch(option)
        {
            case 1:
                input = getDouble("Enter Celcius:");
                answer = cToF(input);
                System.out.printf("Fahrenheit = %.2f\n", answer);
                break;
            case 2:
                input = getDouble("Enter Fahrenheit:");
                answer = cToF(input);
                System.out.printf("Celcius = %.2f\n", answer);
                break;
            case 3:
                System.out.println("Bye bye....");
                System.exit(0);
                break;
            default:
                System.out.println("Invalid input! Please try again.");
        }
    }
    
    /**
     * This program get char input from user
     * @param text prompt text
     * @return char input 
     */
    public static char nextCalculation(String text)
    {
        String input;
        Scanner sc = new Scanner(System.in);
        System.out.print(text);
        input = sc.nextLine().toUpperCase();
        return input.charAt(0);
    }
}
