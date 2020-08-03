class Student3{
    //class variables
    protected String name;
    protected int year1Mark;
    protected int year2Mark;
    protected int year3Mark;
    protected int total;


    //initialising constructor
    public Student3(String n, int m1, int m2, int m3)
    {
        name = n;
        year1Mark = m1;
        year2Mark = m2;
        year3Mark = m3;
    }
    //public method to return student name
    public String getName()
    {
        return name;
    }
    //calculate total
    public int getTotal()
    {
        return year1Mark + year2Mark + year3Mark;
    }
    //public methods to return marks
    public int getTotalMark()
    {
        return getTotal();
    }



}//end class

// This class represents a project student
class ProjectStudent extends Student3
{
    private int courseMark;
    private int projectMark;

    //initialising constructor
    public ProjectStudent(String n, int m1, int m2, int m3, int p)
    {
        super(n,m1,m2,m3);
        projectMark = p;
    }
    //instance method to return the course mark
    public int getTotalMark()
    {
        return (int)( ( (getTotal()/3)*0.8 ) + (projectMark*0.2) );
    }

    public int getProjectMark(){
        return projectMark;
    }
}//end class ProjectStudent


// This class represents a non project student

class NonProjectStudent extends Student3
{
    private int courseMark;

    //initialising constructor
    public NonProjectStudent(String n, int m1, int m2, int m3)
    {
        super(n,m1,m2,m3);
    }

    //instance method to return the course mark
    public int getTotalMark()
    {
        return (int) (super.getTotal() / 3);
    }

    public int getCourseMark(){return courseMark;}
}//end of class NonProjectStudent

class StudentDriver2{
    public static void main(String[] args){
        ProjectStudent alice = new ProjectStudent("Alice",67,72,78,70);
        showCourseMark(alice);

        NonProjectStudent ugeo = new NonProjectStudent("ugeo",60,70,65);
        showCourseMark(ugeo);
    }

    public static void showCourseMark(Student3 s){
        System.out.println(s.getName()+" "+s.getTotalMark()+" ");

        //if project sudent, then display the project mark
        ProjectStudent p;
        if(s instanceof ProjectStudent){
            ProjectStudent prjs = (ProjectStudent) s;
            System.out.println("Project mark= "+ prjs.getProjectMark()+"\n");
        }
    }
}





