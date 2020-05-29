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
public class Week4_Lab5 {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        String value="";
        System.out.println("Please enter the grade(A-F):");
        value = input.next();
        
        int mark =0;
        switch(value.toUpperCase()){
            case "A":
                mark = 70;
                break;
            case "B":
                mark = 60;
                break;
            case "C":
                mark=50;
                break;
            case  "D":
                mark=40;
                break;
            case "E":
                mark=30;
                break;
            case "F":
                mark=20;
                break;
            default:
                mark = -1;
        }
        
        if(mark<0)
            System.out.println("Invalid grade");
        else
            System.out.printf("You scored %d%%\n", mark);
    }
}
