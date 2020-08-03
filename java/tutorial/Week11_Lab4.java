class Student2{
    //class variables
    protected String name;
    protected int id;
    protected String course;
    //initialising constructor
    public Student2(String n, int i, String c)
    {
        name = n;
        id = i;
        course = c;
    }
    //public methods to return student info
    public String getName()
    {
        return name;
    }
    public int getId()
    {
        return id;
    }
    public String getCourse()
    {
        return course;
    }

}//end class

class UndergradStudent extends Student2{
    private String personalTutor;
    UndergradStudent(String n, int i, String c,String t){
        super(n,i,c);
        personalTutor = t;
    }
    public String getPersonalTutor(){return personalTutor;}
}//end class

// This is the driver program to exercise the UndergradStudent
// class
class StudentMain
{
    public static void main(String args[])
    {

        UndergradStudent mike = new
                UndergradStudent("Mike",123,"Computing","Dr Who");

        System.out.println( "Student name: " + mike.getName() );
        System.out.println ( "\nStudent id: " + mike.getId() );
        System.out.println ( "\nStudent course: " + mike.getCourse() );
        System.out.println ( "\nPersonal Tutor: "
                +    mike.getPersonalTutor() );

    }//end main
}//end class StudentMain
