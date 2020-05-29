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

public class Week4_Lab1Extra {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        String str1="",str2="";
        System.out.println("Enter the first word you would like to say during MCO:");
        str1 = input.nextLine();
        System.out.println("Enter the second word you would like to say during MCO");
        str2 =input.nextLine();
        
        //compare with ==
        System.out.println("Using == to compare");
        if (str1 == str2){
            System.out.println("The words are same");
        }else{
            System.out.println("The words are different");
        }
        
        //compare with equal
        System.out.println("Use equals to compare");
        if(str1.equals(str2))
            System.out.println("The words are same");
        else
            System.out.println("The words are different");
        
        //compare with equalsIgnoreCase
        System.out.println("Use equalsIgnoreCase to compare");
        if (str1.equalsIgnoreCase(str2))
            System.out.println("The words are same");
        else
            System.out.println("The words are different");
        
        //compare with compareTo
        System.out.println("Compare with compareTo");
        if(str1.compareTo(str2) > 0){
            System.out.println(str1 +" bigger than "+str2);
        }else if(str2.compareTo(str2)<0){
            System.out.println(str1+" smaller than "+str2);
        }else
            System.out.println("The words are same");
        
        //compare with compareToIgnoreCase
        System.out.println("Compare with compareTo");
        if(str1.compareToIgnoreCase(str2) > 0){
            System.out.println(str1 +" bigger than "+str2);
        }else if(str2.compareToIgnoreCase(str2)<0){
            System.out.println(str1+" smaller than "+str2);
        }else
            System.out.println("The words are same");
    }
}
