
import java.util.Scanner;

public class Week6_Lab2 {
    public static void main(String[] args) {
        double height=0.0,length=0.0,width=0.0;
        Scanner sc = new Scanner(System.in);
        System.out.print("Please enter height:");
        height = sc.nextDouble();
        System.out.print("Please enter width:");
        width = sc.nextDouble();
        System.out.print("Please enter length:");
        length = sc.nextDouble();
        
        double volumn = getVolumn(height,length,width);
        
        System.out.printf("The volumn of the rectangular is %.2f", volumn);
    }
    /**
     * Calculate and return cube volume
     * @param height cube length
     * @param length cube height
     * @param width cube width
     * @return cube volume 
     */
    public static double getVolumn(double height,double length,double width){
        return  height * length * width;
    }
}
