public class Tutorial {
    public static void main(String args[]){
        //object
        Ball b = new Ball();
        b.play("Fly");
    }
}

//template
class Ball{
    double radius;//field, attribute
    static int numBall=0;   //static attribute

    //default constructor
    Ball(){
        numBall++;
        System.out.println("H1");
    }

    //overloaded constructor
    Ball(double r){
        radius = r;
    }

    /**
     * Hi from ball overloaded constructor
     * @param b
     */
    //copy constructor
    Ball(Ball b){
        this.radius = b.radius;
    }

    //method (getter / setter) behavior
    void setRadius(double r){
        radius = r;
    }

    double getRadius(){return radius;}

    //method overloading
    void play(){
        System.out.println("Throw");
    }

    void play(String p){
        System.out.println(p);
    }
}

class Football extends Ball{
    @Override
    void play() {
        System.out.println("Kick");
    }
}

class Basketball extends Ball{
    @Override
    void play() {
        System.out.println("Punch");
    }
}