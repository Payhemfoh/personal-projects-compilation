import java.util.InputMismatchException;
import java.util.Scanner;

public class Week12_Lab2 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int choice = 0;

        //Create an array of String type
        String name[] = {"A","B","C","D","E","F","G","H","I","J"};

        //prompt user to enter a number from 1 to 10
        System.out.printf("Enter a number[1-%d]:",name.length);
        try {
            choice = sc.nextInt();

            System.out.println("The name located at position "+choice+" is "+name[choice-1]);
        }catch(InputMismatchException e){
            System.out.println("Invalid input! Please try again!!");
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println("The number should between 0-"+name.length+"\n"+e.getLocalizedMessage());
        }catch(Exception e){
            System.out.println("Oops! An unexpected error had occur during the process!"+e.getMessage());
        }
    }
}
