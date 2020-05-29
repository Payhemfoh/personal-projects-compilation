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
public class Week4_Lab6 {
    public static void main(String[] args){    
        for(int i=0;i<10;System.out.println(++i)){
        }
        int no=5;
        System.out.println(no++);
        System.out.println(++no);
        Scanner key = new Scanner(System.in);
        int i=0,total=0;
        do{
           
                System.out.println("Please enter the number:");
                i=key.nextInt();
                total+=i;
          
        }while(key.hasNextInt());
        System.out.println(total);
        
        int totala=0;
        for(int input=0;key.hasNextInt();totala+=input){
            try{
                System.out.println("Please enter the number");
                input=key.nextInt();
            }catch(Exception e){
                break;
            }
        }
        System.out.println("Total:"+totala);
        
        Scanner sc = new Scanner(System.in);
        String input = sc.next();
        int acc=0;
        while(input!=null){
            int digit = Integer.parseInt(input);
            acc+=digit;
            input = sc.next();
        }
    }
}
