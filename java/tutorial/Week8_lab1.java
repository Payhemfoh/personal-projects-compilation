public class Week8_lab1 {
    public static void main(String[] args){
        Rectangle rect1 = new Rectangle();
        rect1.setColour("Green");
        rect1.setLength(12);
        rect1.setWidth(20);

        System.out.printf("length:%d\nwidth:%d\ncolour:%s\nArea:%d\nperimeter%d\n",
                rect1.getLength(),
                rect1.getWidth(),
                rect1.getColour(),
                rect1.getArea(),
                rect1.getPerimeter());
    }
}

class Rectangle{
    private int length;
    private int width;
    private String colour;

    public Rectangle(){
        length=0;
        width=0;
        colour="";
    }

    public Rectangle(int length,int width,String colour){
        this.length=length;
        this.width=width;
        this.colour = colour;
    }
    public int getLength(){return length;}
    public int getWidth(){return width;}
    public String getColour(){return colour;}

    public void setLength(int length){this.length = length;}
    public void setWidth(int width){this.width = width;}
    public void setColour(String colour){this.colour = colour;}

    public String toString(){
        return "length="+length+"\twidth="+width;
    }
    public int getArea(){
        return length*width;
    }

    public int getPerimeter(){
        return 2*length+2*width;
    }

    public void makeSquare(){
        if(length>width){
            length=width;
        }else {
            width = length;
        }
        System.out.println("This is a square object!");
    }
}
