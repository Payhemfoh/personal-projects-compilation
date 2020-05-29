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

public class Week5_Lab3 {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int number = 0, total =0;
        
        do{
            System.out.print("Please enter a number: ");
            number = sc. nextInt();
            if(number>0)
                for(int i=0;i<number;i++){
                    total+=i;
                }
            else{
                for(int i=0;i>number;i--){
                    total+=i;
                }
            }
        }while(number!=0);
        
        int no = 0;
        int to = 0;
        int count = 1;
        do{
            System.out.print("enter a number:");
            no = sc.nextInt();

            if(no>0){
                while(count<=no){
                    to+=count;
                    count++;
                }
            }
            else{
                    System.out.println("Number must be a positive value!");
                    //System.exit(0);
                    //to+=count;
                    //count--;
            }
        }while(no<0);
        System.out.printf("The total is %d",to);
    }
}
