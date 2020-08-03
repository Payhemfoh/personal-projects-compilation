//multiplication with recursive
import java.util.Scanner;

public class Week13_Lab2 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter 2 number");
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();

        int result = multiply(num1,num2);
        System.out.println(num1 +" times "+num2+" = "+result);
    }

    public static int multiply(int base, int times){
        if(times==1)
            return base;
        return base+multiply(base,times-1);
    }

    public static int multiply2(int base,int times){
        int total = 0;
        for(int i=0;i<times;++i){
            total += base;
        }
        return total;
    }
}
