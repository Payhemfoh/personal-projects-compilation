public class Week7_Lab1 {
    public static void main(String[] args){
        double num1=5.0,num2=15.0;
        computePercent(num1,num2);
        computePercent(num2,num1);
    }
    public static void computePercent(double num1,double num2){
        double percent = num1/num2 * 100;
        System.out.printf("%.2f is %.0f%% of %.2f\n",num1,percent,num2);
    }
}
