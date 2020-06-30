
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Payhemfoh
 */
public class Week6_Lab5 {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Please enter a sentence:");
        String text = sc.nextLine();
        System.out.print("Please enter a character:");
        char target=sc.next().charAt(0);
        findCharacter(text,target);
    }
    
    /**
     * This method search and print the first occurrence of the character in the sentence
     * @param str the sentence
     * @param target the character to be found in the sentence
     */
     public static void findCharacter(String str,char target)
    {
        boolean found = false;
        int index=0;
        for(int i=0;i<str.length();i++)
        {
            if(str.charAt(i)==target){
                found=true;
                index=i;
                break;
            }
        }
        if(found){
            System.out.printf("The character %s is found at index %d of sentence\n",target,index );
            printLocation(str,index);
        }else{
            System.out.printf("The character %s is not found in the sentence \n",target);
        }
    }
     
     /**
      * This method change the character with index into * and print out
      * @param text the sentence
      * @param index the index of the character
      */
     public static void printLocation(String text,int index)
     {
         String output = text.replace(text.charAt(index),'*');
         
         System.out.println("Result: "+output);
     }
}
