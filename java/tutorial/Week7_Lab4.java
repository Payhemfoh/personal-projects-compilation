import java.util.Scanner;

class Student{
    private int idNumber;
    private int hours;
    private int points;

    public Student(){
        idNumber=9999;
        hours=0;
        points=0;
    }

    public int getIdNumber(){return idNumber;}
    public int getHours(){return hours;}
    public int getPoints(){return points;}

    public void setIdNumber(int id){idNumber = id;}
    public void setHours(int h){hours = h;}
    public void setPoints(int p){points = p;}

    public void showIdNumber(){ System.out.println("ID Number is :"+idNumber); }
    public void showCreditsHour(){ System.out.println("Credit Hours is :"+hours); }
    public void showPoints(){System.out.println("Points Earned is :"+points);}

    public double getGradePoint(){
        return(points*1.0/hours);
    }
}

class Week7_lab4 {
    public static void main(String[] args){
        Student student1 = new Student();

        student1.setIdNumber(234);
        student1.setHours(15);
        student1.setPoints(47);

        student1.showIdNumber();
        student1.showCreditsHour();
        student1.showPoints();

        System.out.printf("The grade point average is %.2f",
                student1.getGradePoint());
    }//end main
}//end class
