/**
 *  Equation class deal with Quadratic Equations
 *  accept input of x y z and total then calculate value of x
 *  x^2 + y^1 + z = total
 *  x = result1;
 *  x = result2;
 * @author Payhemfoh
 */
public class Equation {
    private double x;
    private double y;
    private double z;
    private double total;
    private double result1;
    private double result2;

    public Equation(double x,double y,double z,double total){
        this.x = x;
        this.y = y;
        this.z = z;
        this.total = total;
    }

    public double getX(){ return x; }
    public double getY(){return y;}
    public double getZ(){return z;}
    public double getTotal(){return total;}
    public double getResult1(){return result1;}
    public double getResult2(){return result2;}

    public void setX(double x){this.x = x;}
    public void setY(double y){this.y = y;}
    public void setZ(double z){this.z = z;}
    public void setTotal(double total){this.total = total;}
    public void setResult1(double result){this.result1 = result;}
    public void setResult2(double result){this.result2 = result;}

    public void getResult(){
        if(x == 0){
            this.result1 = 0;
            this.result2 = 0;
        }else {
            double result = ((0 - y) + Math.sqrt((Math.pow(y, 2) - (4 * x * z)))) / (2 * x);
            this.result1 = result;

            result = ((0 - y) - Math.sqrt((Math.pow(y, 2) - (4 * x * z)))) / (2 * x);
            this.result2 = result;
        }
    }

    public String toString(){
        return String.format("%.2fX^2 + %.2fX + %.2f = %.2f\n X = %.2f\n X = %.2f",
                                this.x,this.y,this.z,this.total,this.result1,this.result2);
    }
}
