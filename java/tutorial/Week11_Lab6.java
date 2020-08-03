class MainShape{
    public static void main(String args[]){
        Rectangle2 r = new Rectangle2(2,4);
        r.calculateArea();
        System.out.println("Rectangle area:"+r.getArea());

        Circle c = new Circle(3);
        c.calculateArea();
        System.out.println("Circle area:"+c.getArea());
    }//end main
}//end class

abstract class Shape{
    double area;

    public double getArea(){return area;}
    public abstract void calculateArea();

}

class Rectangle2 extends Shape{
    private double width;
    private double height;

    public Rectangle2(int width,int height){

    }


    @Override
    public void calculateArea(){
        this.area = height*width;
    }
}

class Circle extends Shape{
    private final double PI = 3.14;
    private double radius;
    public Circle(int radius){

    }

    @Override
    public void calculateArea(){
        this.area = PI * radius * radius;
    }
}
