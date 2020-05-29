public class Week3 {
    public static void main(String args[]){
        double a=9;
        double b=7;
        
        double money1=1239238.3242;
        float money2 = (float) money1;
        
        System.out.println(a + "+" + b + "=" + (a+b) );
        System.out.println(a + "-" + b + "=" + (a-b) );
        System.out.println(a + "*" + b + "=" + (a*b) );
        System.out.println(a + "%" + b + "=" + (a%b) );
        System.out.println(a + "/" + b + "=" + (a/b) + "\n");
        
        System.out.printf("%f+%f=%f\n",a,b,a+b);
        System.out.printf("%f-%f=%f\n",a,b,a-b);
        System.out.printf("%f*%f=%f\n",a,b,a*b);
        System.out.printf("%f%%%f=%f\n",a,b,a%b);
        System.out.printf("%f/%f=%f\n",a,b,(float)a/b);
    }
}
