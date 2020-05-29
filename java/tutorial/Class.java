public class Class{
    public static void main(String[] args){
    double a=4.1;
    double s=5.1;
    double d=6.1;
    double sum=a+s+d;
    System.out.println(a+" + "+s+" + "+d+" = "+(a+s+d));
    System.out.println(a+"+"+s+"+"+d+"="+(a+s+d));
    System.out.println(Double.toString(a)+'+'+Double.toString(s)+'+'+Double.toString(d)+'='+Double.toString(a+s+d));
    System.out.printf("%.1f+%.1f+%.1f=%.2f\n", a,s,d,sum);
    
    String name="John Doe";
    System.out.print(name);
    }
}
