import java.util.Scanner;

public class LabTest1 {
    private String name;
    private int mark;

    /*
        main method
     */
    public static void main(String[] args){
        String output   = "";
        LabTest1 obj    = new LabTest1();
        int playerNum   = 1;
        int maximum     = 0;
        String maxIndex    = "";

        //get first input of String
        obj.name = getString("Enter Player Name "+playerNum+" :");

        //repeat while user did not enter Q sentinal value
        while(!obj.getName().equalsIgnoreCase("Q")){
            obj.mark = getMarkInput();

            //if mark is greater than maximum
            if(obj.getMark()>maximum) {
                //replace maximum mark
                maximum = obj.getMark();
                //replace the index String
                maxIndex = Integer.toString(playerNum);
            }
            //if mark is equal to maximum
            else if(obj.getMark()==maximum){
                //concae the index to index String
                maxIndex += Integer.toString(playerNum);
            }

            //format output
            output += obj+"\n";
            playerNum++;

            //get new input for name
            obj.name = getString("Enter Player Name "+playerNum+" :");
        }

        //print the output
        printOutput(output,maxIndex);
    }//end main



    /*
        constructors
     */
    public LabTest1(){
        this.name="";
        this.mark=0;
    }//end constructor

    public LabTest1(String name,int mark){
        this.name=name;
        this.mark=mark;
    }//end constructor



    /*
        getter
     */
    public String getName(){return this.name;}
    public int getMark(){return this.mark;}



    /*
        setter
     */
    public void setName(String name){this.name = name;}
    public void setMark(int mark){this.mark = mark;}



    /*
        toString method
     */
    public String toString(){
        String asterisk="";
        for(int i=0;i<this.mark;i++)
            asterisk+="* ";
        return String.format("%-20s %s", this.name,asterisk);
    }//end method



    /*
        get user inputs
     */
    public static String getString(String text){
        //get String input from user with scanner class
        Scanner sc=  new Scanner(System.in);
        System.out.print(text);
        return sc.nextLine();
    }//end method

    public static int getInteger(String text){
        //get integer input from user with scanner class
        Scanner sc=  new Scanner(System.in);
        System.out.print(text);
        int input=sc.nextInt();
        System.out.println();
        return input;
    }//end method

    public static int getMarkInput(){
        //get the mark input for the instance
        int mark = getInteger("Enter point:");
        while(!is_valid_mark(mark)){
            mark=getInteger("Enter point:");
        }
        return mark;
    }//end method



    /*
        user input validation
     */
    private static boolean is_valid_mark(int mark){
        boolean result=true;
        //the range of mark should between 1 - 10
        if(mark<1 || mark>10) {
            System.out.println("Invalid point! Point must be in range 1-10");
            result = false;
        }
        return result;
    }//end method



    /*
        print out the result
     */
    public static void printOutput(String histogram,String maxIndex){
        //line spacing
        for(int i=0;i<3;i++){
            System.out.println();
        }
        if(maxIndex.length()<=1)
            System.out.printf("%s\nWinner is player %c",histogram,maxIndex.charAt(0));
        else{
            System.out.printf("%s\nWinner are player %c",histogram,maxIndex.charAt(0));

            for(int i=1;i<maxIndex.length();i++){
                System.out.printf(",player %c",maxIndex.charAt(i));
            }
        }
    }//end method

}//end class

