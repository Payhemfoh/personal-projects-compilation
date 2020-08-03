import java.util.ArrayList;

public class SearchModule {
    /**
     * This method will enter the search module which search the object in the list and print out the details of the object
     * @param labList The Array List of the ITLab object
     * @param pcList The Array List of the PC object
     * @param softwareList The Array List of the Software object
     */
    public static void enterSearchModule(ArrayList<ITLab> labList, ArrayList<PC> pcList, ArrayList<Software> softwareList) {
        boolean isContinue = true;
        int option = 0;
        do {

            PrintModule.printSearchMenu();
            option = InputModule.getIntegerInput("Option:");

            switch (option) {
                case 1:
                    searchITLab(labList);
                    break;
                case 2:
                    searchPC(pcList);
                    break;
                case 3:
                    searchSoftware(softwareList);
                    break;
                case 4:
                    System.out.println("Returning to the Main Module...\n");
                    isContinue = false;
                    break;
                default:
                    System.out.println("Invalid input! please try again!");
            }//end switch case

        } while (isContinue);//end do-while loop
    }//end method

    /**
     * This method will search from the list of IT Lab based on the field selected
     * @param list the list of IT Lab
     */
    private static void searchITLab(ArrayList<ITLab> list){
        boolean isContinue = true;
        int option = 0;
        do{
            PrintModule.printSearchLabMenu();
            option = InputModule.getIntegerInput("Option:");

            switch(option){
                case 1:
                    searchITLabByName(list);
                    break;
                case 2:
                    searchITLabByNumPC(list);
                    break;
                case 3:
                    System.out.println("Returning to search module...\n");
                    isContinue = false;
                    break;
                default:
                    System.out.println("Invalid input! Please try again!");
            }//end switch case
        }while(isContinue);//end do-while loop
    }//end method

    /**
     * This method will search from the list of Software based on the field selected
     * @param list the list of Software
     */
    private static void searchSoftware(ArrayList<Software> list){
        boolean isContinue = true;
        int option = 0;
        do{
            PrintModule.printSearchSoftwareMenu();
            option = InputModule.getIntegerInput("Option:");

            switch(option){
                case 1:
                    searchSoftwareByName(list);
                    break;
                case 2:
                    searchSoftwareByType(list);
                    break;
                case 3:
                    searchSoftwareByRam(list);
                    break;
                case 4:
                    searchSoftwareByExpireDate(list);
                    break;
                case 5:
                    System.out.println("Returning to search module...\n");
                    isContinue = false;
                    break;
                default:
                    System.out.println("Invalid input! Please try again!");
            }//end switch case
        }while(isContinue);//end do-while loop
    }//end method

    /**
     * This method will search from the list of PC based on the field selected
     * @param list the list of PC
     */
    private static void searchPC(ArrayList<PC> list){
        boolean isContinue = true;
        int option = 0;
        do{
            PrintModule.printSearchPCMenu();
            option = InputModule.getIntegerInput("Option:");

            switch(option){
                case 1:
                    searchPCByName(list);
                    break;
                case 2:
                    searchPCByIP(list);
                    break;
                case 3:
                    searchPCByType(list);
                    break;
                case 4:
                    searchPCByYearManufacture(list);
                    break;
                case 5:
                    searchPCByRam(list);
                    break;
                case 6:
                    searchPCByLabName(list);
                    break;
                case 7:
                    System.out.println("Returning to search module...\n");
                    isContinue = false;
                    break;
                default:
                    System.out.println("Invalid input! Please try again!");
            }//end switch case
        }while(isContinue);//end do-while loop
    }//end method

    /**
     * This method will search the Software which have the same name as the input from the list
     * @param list the list of software
     */
    private static void searchSoftwareByName(ArrayList<Software> list){
        int count = 0;

        String name = InputModule.getStringInput("Enter name of software:");
        for (Software software : list) {
            if (name.equals(software.getName())) {
                software.print();
                System.out.println();
                ++count;
            }
        }//end Software for loop
        if(count==0){
            System.out.println("No Software which meets the requirement.");
        }
        System.out.println();
    }//end method

    /**
     * This method will search the Software which have the same ram requirement as the input from the list
     * @param list the list of software
     */
    private static void searchSoftwareByRam(ArrayList<Software> list){
        int count = 0;
        double ram = InputModule.getRamInput("Enter Ram Requirement of the Software:");

        for (Software software : list) {
            if (ram == software.getRamRequirement()) {
                software.print();
                System.out.println();
                ++count;
            }
        }//end software for loop

        if(count==0){
            System.out.println("No Software which meets the requirement.");
        }
        System.out.println();
    }//end method

    /**
     * This method will search the Software which have the same name as the input from the list
     * @param list the list of software
     */
    private static void searchSoftwareByExpireDate(ArrayList<Software> list){
        int count = 0;

        String date = InputModule.getDateInput();

        for (Software software : list) {
            if (date.equals(software.getExpireDate())) {
                software.print();
                System.out.println();
                ++count;
            }
        }//end software for loop
        if(count==0){
            System.out.println("No Software which meets the requirement.");
        }
        System.out.println();
    }//end method

    /**
     * This method will search the Software which have the same type as the input from the list
     * @param list the list of software
     */
    private static void searchSoftwareByType(ArrayList<Software> list){
        int count = 0;

        String type = InputModule.getSoftwareTypeInput();

        for (Software software : list) {
            if (type.equals(software.getType())) {
                software.print();
                System.out.println();
                ++count;
            }
        }//end software for loop
        if(count==0){
            System.out.println("No Software which meets the requirement.");
        }
        System.out.println();
    }//end method

    /**
     * This method will search the IT Lab which have the same name as the input from the list
     * @param list the list of IT Lab
     */
    private static void searchITLabByName(ArrayList<ITLab> list){
        int count = 0;

        String name = InputModule.getStringInput("Enter name of ITLab:");

        for (ITLab itLab : list) {
            if (name.equals(itLab.getName())) {
                itLab.print();
                System.out.println();
                ++count;
            }
        }//end for loop
        if(count==0){
            System.out.println("No ITLab which meets the requirement.");
        }
        System.out.println();
    }//end method

    /**
     * This method will search the IT Lab which have the same no. computer as the input from the list
     * @param list the list of IT Lab
     */
    private static void searchITLabByNumPC(ArrayList<ITLab> list){
        int count = 0;
        int numberPC=0;

        do {
            numberPC = InputModule.getIntegerInput("Enter number of PC in ITLab:");

            if(numberPC<0 || numberPC>50)
                System.out.println("Invalid Input! The number of PC should be in range of [0-50]. Please try again!");
        }while(numberPC<0 || numberPC>50);

        for (ITLab itLab : list) {
            if (numberPC == itLab.getNumComputer()) {
                itLab.print();
                System.out.println();
                ++count;
            }
        }//end for loop
        if(count==0){
            System.out.println("No ITLab which meets the requirement.");
        }
        System.out.println();
    }//end method

    /**
     * This method will search the PC which have the same name as the input from the list
     * @param list the list of PC
     */
    private static void searchPCByName(ArrayList<PC> list){
        int count = 0;

        String name = InputModule.getStringInput("Enter name of PC:");

        for (PC pc : list) {
            if (name.equals(pc.getName())) {
                pc.print();
                System.out.println();
                ++count;
            }
        }//end for loop
        if(count==0){
            System.out.println("No PC which meets the requirement.");
        }
        System.out.println();
    }//end method

    /**
     * This method will search the PC which have the same ip as the input from the list
     * @param list the list of PC
     */
    private static void searchPCByIP(ArrayList<PC> list){
        int count = 0;

        IPv4 ip = InputModule.getIPv4Input();

        for (PC pc : list) {
            if (ip.equals(pc.getIp())) {
                pc.print();
                System.out.println();
                ++count;
            }
        }//end for loop
        if(count==0){
            System.out.println("No PC which meets the requirement.");
        }
        System.out.println();
    }//end method

    /**
     * This method will search the PC which have the same lab name as the input from the list
     * @param list the list of PC
     */
    private static void searchPCByLabName(ArrayList<PC> list){
        int count = 0;

        String labname = InputModule.getStringInput("Enter Lab Name of the PC:");

        for (PC pc : list) {
            if (labname.equals(pc.getLabName())) {
                pc.print();
                System.out.println();
                ++count;
            }
        }//end for loop
        if(count==0){
            System.out.println("No PC which meets the requirement.");
        }
        System.out.println();
    }//end method

    /**
     * This method will search the PC which have the same ram requirement as the input from the list
     * @param list the list of PC
     */
    public static void searchPCByRam(ArrayList<PC> list){
        int count = 0;
        double ram = InputModule.getRamInput("Enter Ram Requirement of the PC:");

        for (PC pc : list) {
            if (ram == pc.getRamRequirement()) {
                pc.print();
                System.out.println();
                ++count;
            }
        }//end for loop
        if(count==0){
            System.out.println("No PC which meets the requirement.");
        }
        System.out.println();
    }//end method

    /**
     * This method will search the PC which have the same type as the input from the list
     * @param list the list of PC
     */
    public static void searchPCByType(ArrayList<PC> list){
        int count = 0;

        String type = InputModule.getPCTypeInput();
        for (PC pc : list) {
            if (type.equals(pc.getComputerType())) {
                pc.print();
                System.out.println();
                ++count;
            }
        }//end for loop
        if(count==0){
            System.out.println("No PC which meets the requirement.");
        }
        System.out.println();
    }//end method

    /**
     * This method will search the PC which have the same year manufacture as the input from the list
     * @param list the list of PC
     */
    public static void searchPCByYearManufacture(ArrayList<PC> list){
        int count = 0;
        int year = InputModule.getYearInput("Enter year manufacture of the PC:");

        for (PC pc : list) {
            if (year == pc.getYearManufacture()) {
                pc.print();
                System.out.println();
                ++count;
            }
        }//end for loop
        if(count==0){
            System.out.println("No PC which meets the requirement.");
        }
        System.out.println();
    }//end method
}//end class
