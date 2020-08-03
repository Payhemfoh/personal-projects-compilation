import java.util.InputMismatchException;
import java.util.Scanner;

public class Week12_Lab9 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int result = 0;
        boolean repeat = false;

        do {
            try {
                System.out.println("Enter 2 numbers:");
                int no1 = sc.nextInt();
                int no2 = sc.nextInt();

                result = no1 / no2;

                repeat = false;
            } catch (InputMismatchException e) {
                System.out.println("Only numeric number can be entered! Please try again!");
                repeat = true;
                sc.nextLine();
            }catch(ArithmeticException e){
                System.out.println("The second number should not be zero! Please try again!");
                repeat = true;
            }catch(Exception e){
                System.out.println("Invalid input, please try again!");
                repeat = true;
            }

        }while(repeat);
        System.out.println(result);
    }//end main
}//end class

class DebugProgram
{
    public static void main(String[] args)
    {
        double num = -8.8, result;
        try
        {
            if(num <= 0)
                throw(new ArithmeticException());
            result = Math.log(num);
            System.out.println("Result is " + result);
        }
        catch(ArithmeticException e)
        {
            System.out.println("Can't take logarithm for value of zero or lower");
        }
    }
}

