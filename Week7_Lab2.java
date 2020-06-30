import java.util.Scanner;

public class Week7_Lab2 {
    final static double CM_FROM_INCH = 2.54;
    final static double LITER_FROM_GALLON = 3.7854;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        double value=0.0;

        System.out.println("Enter a value:");
        value = sc.nextDouble();

        printAll(value);
    }//end main

    public static double inchToCm(double inch){
        double cm = inch*CM_FROM_INCH;
        System.out.printf("%.2f -> %.2f\n",inch,cm);
        return cm;
    }

    public static double gallonToLiter(double gallon){
        double liter = gallon*LITER_FROM_GALLON;
        System.out.printf("%.2f -> %.2f\n",gallon,liter);
        return liter;
    }

    public static double cmToInch(double cm){
        double inch = cm/CM_FROM_INCH;
        System.out.printf("%.2f -> %.2f\n",cm,inch);
        return inch;
    }

    public static double literToGallon(double liter){
        double gallon = liter/LITER_FROM_GALLON;
        System.out.printf("%.2f -> %.2f\n",liter,gallon);
        return gallon;
    }

    public static void printAll(double value){
        inchToCm(value);
        cmToInch(value);
        gallonToLiter(value);
        literToGallon(value);
    }
}//end class
