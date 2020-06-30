import java.util.Scanner;

public class Week7_lab3 {
    public static void main(String[] args){
        double hourlyRate =0.0,regularHour=0.0,overtimeHour=0.0;
        double salary=0.0;

        hourlyRate=getDoubleValue("Enter hourly rate:");
        regularHour=getDoubleValue("Enter hourly rate:");
        overtimeHour=getDoubleValue("Enter hourly rate:");

        //calculate salary
        salary=computeSalary(hourlyRate,regularHour,overtimeHour);

        System.out.printf("The salary is RM%.2f",salary);
    }//end main

    public static double getDoubleValue(String text){
        Scanner sc = new Scanner(System.in);
        System.out.print(text);
        double input=sc.nextDouble();
        return input;
    }

    public static double computeSalary(double rate,double regular,double over){
        double salary = (rate * regular) + (over * rate*1.5);
        return salary;
    }
}//end class
