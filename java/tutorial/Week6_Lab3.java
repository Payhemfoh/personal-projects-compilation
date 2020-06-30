
public class Week6_Lab3 {
    public static void main(String args[]){
        for (int radius = 0; radius < 5 ; radius++)
            printArea(radius);
        for (double  radius = 0; radius < 2.6 ; radius+= 0.5)
            printArea(radius);
    }
    
    /**
     * Calculate the area with the radius given and print out the value
     * @param r radius of circle(integer value)
     */
    public static void printArea(int r)
    {
       double area = (22.0/7)*r*r;
        System.out.printf("Radius:%d\tArea:%.2f\n", r,area);
    }
    
    
    /**
     * Calculate the area with the radius given and print out the value
     * @param r radius of circle(double value)
     */
    public static void printArea(double r)
    {
        double area = (22.0/7)*r*r;
        System.out.printf("Radius:%.2f\tArea:%.2f\n", r,area);
    }
}
