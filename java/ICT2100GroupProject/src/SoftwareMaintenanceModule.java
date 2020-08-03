import java.util.ArrayList;

public class SoftwareMaintenanceModule {

    /**
     * This is the software maintenance module which modify the ArrayList of Software object
     * @param softwareList The ArrayList of the Software object
     */
    public static void enterSoftwareMaintenanceModule(ArrayList<ITLab> labList,ArrayList<PC> pcList,ArrayList<Software> softwareList){
        boolean isContinue = true;
        int option = 0;

        try {
            do {
                PrintModule.printSoftwareMenu();
                option = InputModule.getIntegerInput("Option:");
                switch (option) {
                    case 1:
                        //add software
                        addSoftware(softwareList);
                        break;
                    case 2:
                        //modify software
                        modifySoftware(labList, pcList, softwareList);
                        break;
                    case 3:
                        //remove software
                        removeSoftware(labList, pcList, softwareList);
                        break;
                    case 4:
                        printSoftwareDetail(softwareList);
                        break;
                    case 5:
                        //exit loop and return to main menu
                        isContinue = false;
                        System.out.println("Returning to Main Module...\n");
                        break;
                    default:
                        //invalid option
                        System.out.println("Invalid option! Please try again!");
                }//end switch case

            } while (isContinue);//end do while loop

        }catch(Exception e){
            System.out.println("Unexpected Error occur during the process."+e.getMessage());
            System.exit(-1);
        } finally{
            //write data into file before exit module
            FileManagementModule.writeSoftware(softwareList);
            FileManagementModule.writePC(pcList);
            FileManagementModule.writeLab(labList);
        }
    }//end method

    /**
     * This method is used to create new software profile and add into the software list
     * @param list the software list
     */
    private static void addSoftware(ArrayList<Software> list){
        boolean repeat = false;
        do {
            try {
                String name = InputModule.getSoftwareName(list);
                String type = InputModule.getSoftwareTypeInput();
                double ramRequirement = InputModule.getRamInput("Enter Ram Requirement of the Software(GB):");
                String expireDate;
                if(!type.equals("Freeware")) {
                    expireDate = InputModule.getDateInput();
                }else{
                    expireDate = "";
                }
                Software s = new Software(name, type, ramRequirement, expireDate);

                for (Software software : list)
                    if (s.equals(software))
                        throw new AssertionError();

                list.add(s);
                System.out.println("The Software profile is created successfully.\n");
                repeat = false;
            }catch(AssertionError e){
                System.out.println("Oops!The Software already exists in the list! Please try again!");
                repeat = true;
            }catch(Exception e){
                System.out.println("Oops! An unexpected error had occur during the process."+e.getMessage());
                repeat = true;
            }//end catch block
        }while(repeat);//end do-while loop
    }//end method

    /**
     * This method is used to modify the Software profile.
     * The user will be given a table of software list and fields to select and input.
     * @param labList the list of IT Lab
     * @param pcList the list of PC
     * @param softwareList the list of Software
     */
    private static void modifySoftware(ArrayList<ITLab> labList,ArrayList<PC> pcList,ArrayList<Software> softwareList){
        boolean isContinue = true;
        int option = 0;
        final int SIZE = softwareList.size();

        do {
            PrintModule.printSoftwareList(softwareList);
            System.out.println("----------------------------------------");
            System.out.printf("Enter %d to return to Software Maintenance Module.\n", SIZE + 1);

            option = InputModule.getIntegerInput("Please enter the index of software to edit:");


            if (option > 0 && option <= SIZE) {
                Software ptr = softwareList.get(option-1);
                boolean innerLoop = true;

                do {
                    ptr.print();
                    System.out.println();
                    PrintModule.printSoftwareEditMenu();
                    option = InputModule.getIntegerInput("Option:");

                    switch (option) {
                        case 1:
                            String name= InputModule.getSoftwareName(softwareList);
                            for (PC comPtr : pcList) {
                                if (comPtr.hasSoftware(ptr)) {
                                    comPtr.getSoftware(ptr).setName(name);
                                }
                            }
                            ptr.setName(name);
                            System.out.println("The software profile had been updated.\n");
                            break;
                        case 2:
                            String type = InputModule.getSoftwareTypeInput();
                            for (PC comPtr : pcList) {
                                if (comPtr.hasSoftware(ptr)) {
                                    comPtr.getSoftware(ptr).setType(type);
                                }
                            }//end PC for loop
                            ptr.setType(type);
                            System.out.println("The software profile had been updated.\n");
                            break;
                        case 3:
                            double ram = InputModule.getRamInput("Enter Ram Requirement of Software(GB):");
                            for (PC comPtr : pcList) {
                                //if comPtr has the software
                                if (comPtr.hasSoftware(ptr)) {
                                    comPtr.getSoftware(ptr).setRamRequirement(ram);
                                }
                            }//end PC for loop
                            ptr.setRamRequirement(ram);
                            System.out.println("The software profile had been updated.\n");
                            break;
                        case 4:
                            String date = InputModule.getDateInput();
                            for (PC comPtr : pcList) {
                                if (comPtr.hasSoftware(ptr)) {
                                    comPtr.getSoftware(ptr).setExpireDate(date);
                                }
                            }
                            ptr.setExpireDate(date);
                            System.out.println("The software profile had been updated.\n");
                            break;
                        case 5:
                            System.out.println("Returning to Software Selection Page...\n");
                            innerLoop = false;
                            break;
                        default:
                            System.out.println("Invalid input, Please try again!");
                    }//end switch case
                }while(innerLoop);//end inner do-while loop
            } //end if
            else if(option == SIZE+1){
                System.out.println("Returning to Software Management Page...\n");
                isContinue = false;
            }
            else {
                System.out.println("The option is out of range, please try again !");
            }//end else
        }while(isContinue);//end do-while loop
    }//end method

    /**
     * This method is used to remove the software profile
     * The user is given a table of software list and select which should be delete.
     * @param labList the list of IT Lab
     * @param pcList the list of PC
     * @param softwareList the list of Software
     */
    private static void removeSoftware(ArrayList<ITLab> labList,ArrayList<PC> pcList,ArrayList<Software> softwareList){
        boolean isContinue = true;
        int option = 0;
        char confirm='\0';

        do {
            int size = softwareList.size();
            PrintModule.printSoftwareList(softwareList);
            System.out.println("----------------------------------------");
            System.out.printf("Enter %d to return to PC Maintenance Module.\n", size + 1);

            option = InputModule.getIntegerInput("Please enter the index of software to delete:");


            if (option > 0 && option <= size) {
                Software ptr = softwareList.get(option-1);
                ptr.print();
                System.out.println("Are you sure you want to delete the Software?[Y/N]");
                confirm = InputModule.getCharOption();

                //confirmation
                if (confirm == 'y' || confirm == 'Y') {
                    for (PC comPtr : pcList) {
                        if (comPtr.hasSoftware(ptr)) {
                            if (!comPtr.getLabName().equals("--")) {
                                for (ITLab itLab : labList) {
                                    if (itLab.getName().equals(comPtr.getLabName())) {
                                        int index = itLab.getComputerPos(comPtr);
                                        itLab.getPC(index).removeSoftware(ptr);
                                    }
                                }
                            }
                            comPtr.removeSoftware(ptr);
                        }
                    }//end PC for loop

                    softwareList.remove(option - 1);
                    System.out.println("The software has been removed.\n");
                }
                else {
                    System.out.println("The software was not removed.\n");
                }

            } //end else if
            else if(option == size+1){
                System.out.println("Returning to Software Management Page...\n");
                isContinue = false;
            }
            else {
                System.out.println("The option is out of range, please try again !");
            }//end else

        }while(isContinue);//end do while
    }//end method

    /**
     * This method is used to display the details of the software profiles
     * The user is given a table of software list to select which software profiles to be display
     * @param list the list of software
     */
    private static void printSoftwareDetail(ArrayList<Software> list){
        boolean isContinue = true;
        int option = 0;
        final int SIZE = list.size();

        do {
            PrintModule.printSoftwareList(list);
            System.out.println("----------------------------------------");
            System.out.printf("Enter %d to return to PC Maintenance Module.\n", SIZE + 1);
            option = InputModule.getIntegerInput("Option:");

            if(option>0 && option<=SIZE){
                list.get(option-1).print();
                System.out.println();
            }else if(option == SIZE+1){
                System.out.println("Returning to Software Management Page...\n");
                isContinue = false;
            }
            else {
                System.out.println("The option is out of range, please try again !");
            }//end else
        }while(isContinue);//end do-while loop
    }//end method
}//end class
