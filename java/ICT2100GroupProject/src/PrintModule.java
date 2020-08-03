import java.util.ArrayList;

public class PrintModule {
    /**
     * This method will print the main menu of the program which should be used in the main method
     */
    public static void printMainMenu() {
        System.out.println("SOFTWARE TRACKING SYSTEM");
        System.out.println("----------------------------------------");
        System.out.println("1. Lab Maintenance");
        System.out.println("2. PC Maintenance");
        System.out.println("3. Software Maintenance");
        System.out.println("4. Search");
        System.out.println("5. Export To HTML file");
        System.out.println("6. Exit The Program");
        System.out.println("----------------------------------------");
    }//end method

    /**
     * This method will print the menu used in the search module
     */
    public static void printSearchMenu(){
        System.out.println("Search Module");
        System.out.println("----------------------------------------");
        System.out.println("Please select which of the following do you want to search:");
        System.out.println("1. ITLab");
        System.out.println("2. PC");
        System.out.println("3. Software");
        System.out.println("4. Exit");
        System.out.println("----------------------------------------");
    }//end method

    /**
     * This method will print the menu when user want to search Lab in search module
     */
    public static void printSearchLabMenu(){
        System.out.println("Please choose a field for search:");
        System.out.println("----------------------------------------");
        System.out.println("1. Name");
        System.out.println("2. Number of PC");
        System.out.println("3. Exit");
        System.out.println("----------------------------------------");
    }//end method

    /**
     * This method will print the menu when user want to search PC in search module
     */
    public static void printSearchPCMenu(){
        System.out.println("Please choose a field for search:");
        System.out.println("----------------------------------------");
        System.out.println("1. Name");
        System.out.println("2. IP");
        System.out.println("3. Computer Type");
        System.out.println("4. Year Manufacture");
        System.out.println("5. Ram Requirement");
        System.out.println("6. Lab Name");
        System.out.println("7. Exit");
        System.out.println("----------------------------------------");
    }//end method

    /**
     * This method will print the menu when user want to search Software in search module
     */
    public static void printSearchSoftwareMenu(){
        System.out.println("Please choose a field for search:");
        System.out.println("----------------------------------------");
        System.out.println("1. Name of software");
        System.out.println("2. Type of software");
        System.out.println("3. Ram Requirement of software");
        System.out.println("4. Expire Date of software");
        System.out.println("5. Exit");
        System.out.println("----------------------------------------");
    }//end method

    /**
     * This method will print the table for user to select when software type input is required
     */
    public static void printSoftwareTypeSelectMenu(){
        System.out.println("Select The Type Of Software:");
        System.out.println("----------------------------------------");
        System.out.println("1.Proprietary");
        System.out.println("2.Shareware");
        System.out.println("3.Freeware");
        System.out.println("----------------------------------------");
    }//end method

    /**
     * This method will print the table for user to select when pc type input is required
     */
    public static void printPCTypeSelectMenu(){
        System.out.println("Select The Type Of PC:");
        System.out.println("----------------------------------------");
        System.out.println("1.Desktop");
        System.out.println("2.Laptop");
        System.out.println("----------------------------------------");
    }//end method

    /**
     * This method will print the software maintenance menu which should be used in software maintenance module
     */
    public static void printSoftwareMenu(){
        System.out.println("Software Maintenance Module");
        System.out.println("----------------------------------------");
        System.out.println("1. Create New Software Profile");
        System.out.println("2. Modify Existing Software Profile");
        System.out.println("3. Delete Software Profile");
        System.out.println("4. Display Software Details");
        System.out.println("5. Exit The Module");
        System.out.println("----------------------------------------");
    }//end method

    /**
     * This method will print the menu for user to select which field to edit on the software
     */
    public static void printSoftwareEditMenu(){
        System.out.println("Please select which field do you want to edit");
        System.out.println("----------------------------------------");
        System.out.println("1. Name");
        System.out.println("2. Software Type");
        System.out.println("3. Ram Requirement");
        System.out.println("4. Expire Date");
        System.out.println("5. Exit");
        System.out.println("----------------------------------------");
    }//end method

    /**
     * This method will print the pc maintenance menu which should be used in pc maintenance module
     */
    public static void printPCMenu(){
        System.out.println("PC Maintenance Module");
        System.out.println("----------------------------------------");
        System.out.println("1. Create New PC Profile");
        System.out.println("2. Modify Existing PC Profile");
        System.out.println("3. Add Software to PC");
        System.out.println("4. Remove Software to PC");
        System.out.println("5. Delete PC Profile");
        System.out.println("6. Display PC Details");
        System.out.println("7. Exit The Module");
        System.out.println("----------------------------------------");
    }//end method

    /**
     * This method will print the menu for user to select which field to edit on the pc
     */
    public static void printPCEditMenu(){
        System.out.println("Please select which field do you want to edit");
        System.out.println("----------------------------------------");
        System.out.println("1. Name");
        System.out.println("2. IP address");
        System.out.println("3. Computer type");
        System.out.println("4. Ram Requirement");
        System.out.println("5. Year of Manufacture");
        System.out.println("6. Exit");
        System.out.println("----------------------------------------");
    }//end method

    /**
     * This method will print the menu for user to select which field to edit on the lab
     */
    public static void printITLabEditMenu(){
        System.out.println("Please select which field do you want to edit");
        System.out.println("----------------------------------------");
        System.out.println("1. Name");
        System.out.println("2. Exit");
        System.out.println("----------------------------------------");
    }//end method

    /**
     * This method will print the lab maintenance menu which should be used in lab maintenance module
     */
    public static void printLabMenu(){
        System.out.println("Lab Maintenance Module");
        System.out.println("----------------------------------------");
        System.out.println("1. Create New Lab Profile");
        System.out.println("2. Modify Existing Lab Profile");
        System.out.println("3. Assign PC To Lab");
        System.out.println("4. Remove PC From Lab");
        System.out.println("5. Delete Lab Profile");
        System.out.println("6. Display Lab Details");
        System.out.println("7. Exit The Module");
        System.out.println("----------------------------------------");
    }//end method

    /**
     * This method will print the list of software in table form
     * @param list the list of software
     */
    public static void printSoftwareList(ArrayList<Software> list){
        final int SIZE = list.size();

        System.out.printf("%-6s| %-30s\n", "Index", "Software");
        System.out.println("----------------------------------------");

        for (int i = 0; i < SIZE; ++i) {
            System.out.printf("%-6d| %-30s\n", i+1, list.get(i).getName());
        }//end for loop
    }//end method

    /**
     * This method will print the list of pc in table form
     * @param list the list of pc
     */
    public static void printPCList(ArrayList<PC> list){
        final int SIZE = list.size();

        System.out.printf("%-6s| %-30s\n","Index","PC");
        System.out.println("----------------------------------------");

        for(int i=0;i<SIZE;++i){
            System.out.printf("%-6d| %-30s\n",i+1,list.get(i).getName());
        }//end for loop
    }//end method

    /**
     * This method will print the list of IT Lab in table form
     * @param list the list of IT Lab
     */
    public static void printLabList(ArrayList<ITLab> list){
        final int SIZE = list.size();

        System.out.printf("%-6s| %-30s\n","Index","Lab Profile Name");
        System.out.println("----------------------------------------");

        for(int i=0;i<SIZE;++i){
            System.out.printf("%-6d| %-30s\n",i+1,list.get(i).getName());
        }//end for loop
    }//end method
}//end class
