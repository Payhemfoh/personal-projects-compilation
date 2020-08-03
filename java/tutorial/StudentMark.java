/**
 *
 * @author Lai
 */
import java.util.Scanner;

public class StudentMark {
    private String id;
    private int mark;

    /**
     * Default constructor
     */
    public StudentMark() {
       this("",0); 
    }

    /**
     * Overloaded constructor
     * @param id    student id
     * @param mark  student's mark
     */
    public StudentMark(String id, int mark) {
        this.id = id;
        this.mark = mark;
        
    }

    /*
        getter and setter to get and change the private instances
     */
    public String getId() {return id;}
    public int getMark() {return mark;}
    public void setId(String id) {this.id = id;}
    public void setMark(int mark) {
        if (mark>=0)
            this.mark = mark;        
    }

    /**
     * toString() method to print out the student id and mark directly
     * @return string of student information
     */
    @Override
    public String toString() {
        return "[ID="+id + ", Mark=" + mark + "]";
    }
    
    //TASK: You have to override the equals method at here

    /**
     * equals() method to compare all the instances of the objects under the class
     * @param obj the object to compare(need to be validate either have same class)
     * @return  boolean result either all instances of the objects are same
     */
    @Override
    public boolean equals(Object obj){
        //check if the param point to null
        if(obj==null)
            return false;

        //check class of object
        if(this.getClass()!=obj.getClass())
            return false;

        boolean result = false;

        //cast the object so that the Object is treat as StudentMark object
        //and assign to the new StudentMark object
        StudentMark param = (StudentMark)obj;
        //check if id and mark are same value
        if(id.equalsIgnoreCase(param.getId()) && mark == param.getMark()){
            result = true;
        }

        return result;
    }
    
}

class Module{
    private StudentMark[] studentMarkList;
    private int count;

    /**
     * Default constructor
     */
    public Module(){
        studentMarkList = new StudentMark[10];
        count=0;
    }

    /*
        getter to get the private instances
     */
    public int getCount(){return count;}
    public StudentMark[] getStudentMarkList(){return studentMarkList;}

    /**
     * add a StudentMark object into the array which is the instance under this class
     * @param m StudentMark object to be added into array
     */
    public void addStudentMark(StudentMark m){
        if(count==10)
            System.out.println("Oops!The Student Mark List is fulled!!");
        else {
            studentMarkList[count] = m;
            ++count;
        }
    }

    /**
     * method to print all the StudentMark object in list in tabular format
     */
    public void printMarkList(){
        System.out.printf("%-10s%-5s\n","Id","Mark");
        System.out.println("-------------------");
        for(int i=0;i<count;i++){
            System.out.printf("%-10s%-5d\n",studentMarkList[i].getId(),studentMarkList[i].getMark());
        }
        System.out.println("\n\n");
    }

    /**
     * method to get the average mark of the StudentMark object in the list
     * @return the average mark of StudentMark object in the list
     */
    public double getAverageMark(){
        //calculate the total
        int total=0;
        for(int i=0;i<count;i++){
            total+=studentMarkList[i].getMark();
        }
        //calculate and return average
        return 1.0*total/count;
    }
}

class StudentModuleDriver{
    /**
     * main class to interact with the methods in StudentMark and Module classes
     * @param args  parameter from console
     */
    public static void main(String[] args){
        //Create a Module object
        Module sample = new Module();

        //Create StudentMark objects
        //check if the StudentMark object already present in array
        //add the object into array if not present
        //if the object present, print error message
        StudentMark s1 = new StudentMark();
        s1.setId("S01");
        s1.setMark(99);
        addStudent(sample,s1);
        s1 = new StudentMark("S02",39);
        //loop until the list of StudentMark is full
        while(sample.getCount()<10) {
            addStudent(sample, s1);
            s1 = getStudentMark();
        }


        //print StudentMark object in list in tabular format
        sample.printMarkList();

        //print the average mark of the StudentMark object in list
        System.out.printf("The average mark of the students is %.2f\n",sample.getAverageMark());
    }

    /**
     * method to get string input from user
     * @param prompt    prompt text for the user
     * @return  the string input entered by the user
     */
    public static String getStringInput(String prompt){
        Scanner sc = new Scanner(System.in);
        System.out.print(prompt);
        return sc.nextLine();
    }

    /**
     * method to get integer input from user
     * @param prompt    prompt text for the user
     * @return  the integer input entered by the user
     */
    public static int getIntegerInput(String prompt){
        Scanner sc = new Scanner(System.in);
        System.out.print(prompt);
        return sc.nextInt();
    }

    /**
     * method to create a new StudentMark object and return the address of the object created
     * @return  address of the StudentMark object created
     */
    public static StudentMark getStudentMark(){
        String id="";
        int mark=0;
        String idInput = getStringInput("Enter ID:");
        //if Input string is long then 3 character
        if(idInput.length()>3){
            //the last 3 character is the id of student.
            id = idInput.substring(idInput.length()-3).toUpperCase();
        }else{
            id = idInput.toUpperCase();
        }
        mark = getIntegerInput("Enter mark:");
        return new StudentMark(id,mark);
    }

    /**
     * method to check either the target StudentMark object is present in the array
     * and add the target into the array is not present.
     * @param m  the Module object which contain the StudentMark array
     * @param target    the target to check either the object is in array
     */
    public static void addStudent(Module m,StudentMark target){
        boolean isPresent = false;
        StudentMark[] array = m.getStudentMarkList();


        //loop every present object in array
        for(int i=0;i<m.getCount();++i){
            if(array[i].equals(target)){
                isPresent = true;
            }
        }

        if(isPresent){
            System.out.println("The student already present in the list!");
        }else{
            m.addStudentMark(target);
        }
    }
}