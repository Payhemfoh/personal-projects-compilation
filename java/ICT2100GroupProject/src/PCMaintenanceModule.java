import java.util.ArrayList;

public class PCMaintenanceModule {
    /**
     * This is the pc maintenance module which modify the Array List of pc object
     * @param pcList The ArrayList of pc object
     */
    public static void enterPCMaintenanceModule(ArrayList<ITLab> labList,ArrayList<PC> pcList,ArrayList<Software> softwareList){
        boolean isContinue = true;
        int option = 0;

        try{
            do{
                PrintModule.printPCMenu();
                option = InputModule.getIntegerInput("Option:");

                switch(option){
                    case 1:
                        addPC(pcList,softwareList);
                        break;
                    case 2:
                        editPC(labList,pcList,softwareList);
                        break;
                    case 3:
                        addSoftware(labList,pcList,softwareList);
                        break;
                    case 4:
                        deleteSoftware(labList,pcList);
                        break;
                    case 5:
                        deletePC(labList,pcList);
                        break;
                    case 6:
                        displayPCDetail(pcList);
                        break;
                    case 7:
                        isContinue = false;
                        System.out.println("Returning to Main Module...\n");
                        break;
                    default:
                        System.out.println("Invalid option:Please try again!");
                }//end switch
            }while(isContinue);//end do-while loop
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

    private static void addPC(ArrayList<PC> list,ArrayList<Software> softwareList){
        boolean repeat = false;
        do{
            try {
                String name = InputModule.getPCName(list);
                IPv4 ip = InputModule.getIPv4Input();
                String type = InputModule.getPCTypeInput();
                int year = InputModule.getYearInput("Enter year manufacture of PC:");
                double ram = InputModule.getRamInput("Enter Ram Requirement of PC(GB):");

                PC temp = new PC(name, ip, type, year, ram);

                for (PC pc : list){
                    if (temp.equals(pc))
                        throw new AssertionError();
                }//end PC for loop

                int option = 0;
                final int SOFTWARESIZE = softwareList.size();
                while(temp.getNumSoftware()<1){
                    System.out.println("Please assign the OS of the PC:");
                    PrintModule.printSoftwareList(softwareList);
                    option = InputModule.getIntegerInput("Option:");

                    if(option>0 && option<=SOFTWARESIZE){
                        temp.addSoftware(softwareList.get(option-1));
                        System.out.println("The Software had been added to the software list of this PC");
                    }else{
                        System.out.println("Invalid Input! Your option had out of scope!");
                    }
                }//end while loop

                list.add(temp);
                System.out.println("The PC profile had been created successfully.\n");
                repeat = false;
            }catch(AssertionError e){
                System.out.println("Oops!The PC already exists in the list! Please try again!");
                repeat = true;
            }catch(Exception e){
                System.out.println("Oops! An unexpected error had occur during the process."+e.getMessage());
                repeat = true;
            }
        }while(repeat);//end do-while loop
    }//end method

    private static void editPC(ArrayList<ITLab> labList,ArrayList<PC> list,ArrayList<Software> softwareList){
        final int SIZE = list.size();
        int option = 0;
        boolean isContinue= true;

        do {
            PrintModule.printPCList(list);
            System.out.println("----------------------------------------");
            System.out.printf("Enter %d to return to PC Maintenance Module.\n", SIZE + 1);
            option = InputModule.getIntegerInput("Option:");

            if (option > 0 && option <= SIZE) {
                PC ptr = list.get(option-1);
                boolean innerLoop = true;

                do {
                    ptr.print();
                    System.out.println();
                    PrintModule.printPCEditMenu();
                    option = InputModule.getIntegerInput("Option:");

                    switch (option) {
                        case 1:
                            String name = InputModule.getPCName(list);
                            if(!ptr.getLabName().equals("--")){
                                for (ITLab itLab : labList) {
                                    if (ptr.getLabName().equals(itLab.getName())) {
                                        itLab.getPC(ptr).setName(name);
                                        break;
                                    }
                                }
                            }
                            ptr.setName(name);
                            break;
                        case 2:
                            IPv4 ip = InputModule.getIPv4Input();
                            if(!ptr.getLabName().equals("--")){
                                for (ITLab itLab : labList) {
                                    if (ptr.getLabName().equals(itLab.getName())) {
                                        itLab.getPC(ptr).setIp(ip);
                                        break;
                                    }
                                }
                            }
                            ptr.setIp(ip);
                            break;
                        case 3:
                            String type =InputModule.getPCTypeInput();
                            if(!ptr.getLabName().equals("--")){
                                for (ITLab itLab : labList) {
                                    if (ptr.getLabName().equals(itLab.getName())) {
                                        itLab.getPC(ptr).setComputerType(type);;
                                        break;
                                    }
                                }
                            }
                            ptr.setComputerType(type);
                            break;
                        case 4:
                            double ram = InputModule.getRamInput("Emter Ram Requirement of PC(GB):");
                            if(!ptr.getLabName().equals("--")){
                                for (ITLab itLab : labList) {
                                    if (ptr.getLabName().equals(itLab.getName())) {
                                        itLab.getPC(ptr).setRamRequirement(ram);
                                        break;
                                    }
                                }
                            }
                            ptr.setRamRequirement(ram);
                            break;
                        case 5:
                            int year = InputModule.getYearInput("Enter year manufacture of PC:");
                            if(!ptr.getLabName().equals("--")){
                                for (ITLab itLab : labList) {
                                    if (ptr.getLabName().equals(itLab.getName())) {
                                        itLab.getPC(ptr).setYearManufacture(year);;
                                        break;
                                    }
                                }
                            }
                            ptr.setYearManufacture(year);
                            break;
                        case 6:
                            System.out.println("Returning to Software Selection Page...\n");
                            innerLoop = false;
                            break;
                        default:
                            System.out.println("Invalid input, Please try again!");
                    }//end switch case
                }while(innerLoop);//end inner do-while loop
                isContinue = true;

            }else if(option == SIZE+1){
                System.out.println("Returning to PC Maintenance Module...\n");
                isContinue = false;
            } else {
                System.out.println("Invalid Input! Please try again!");
            }
        }while(isContinue);//end do-while loop
    }//end method

    private static void deletePC(ArrayList<ITLab> labList,ArrayList<PC> list){
        int option = 0;
        char confirm = '\0';
        boolean isContinue = true;

        do {
            int size = list.size();
            PrintModule.printPCList(list);
            System.out.println("----------------------------------------");
            System.out.printf("Enter %d to return to PC Maintenance Module.\n", size + 1);
            option = InputModule.getIntegerInput("Option:");

            if (option > 0 && option <= size) {
                PC ptr = list.get(option-1);
                ptr.print();
                System.out.println("Are you sure you want to delete the PC?[Y/N]");
                confirm = InputModule.getCharOption();

                if (confirm == 'y' || confirm == 'Y') {
                    if(!ptr.getLabName().equals("--")){
                        for (ITLab itLab : labList) {
                            if (ptr.getLabName().equals(itLab.getName())) {
                                itLab.removePC(ptr);
                                break;
                            }
                        }
                    }

                    list.remove(option - 1);
                    System.out.println("The PC has been deleted.\n");
                } else {
                    System.out.println("The PC has not been deleted.\n");
                }
            }else if(option == size+1){
                System.out.println("Returning to PC Maintenance Module...\n");
                isContinue = false;
            } else {
                System.out.println("Invalid Input! Please try again!");
            }
        }while(isContinue);//end do-while loop
    }//end method

    private static void displayPCDetail(ArrayList<PC> list){
        final int SIZE = list.size();
        int option = 0;
        boolean isContinue = true;
        do {
            PrintModule.printPCList(list);
            System.out.println("----------------------------------------");
            System.out.printf("Enter %d to return to PC Maintenance Module.\n", SIZE + 1);
            option = InputModule.getIntegerInput("Option:");

            if(option>0&&option<=SIZE){
                list.get(option-1).print();
                System.out.println();
            }else if(option==SIZE+1){
                System.out.println("Returning to PC Maintenance Module...\n");
                isContinue = false;
            } else {
                System.out.println("Invalid Input! Please try again!");
            }
        }while(isContinue);//end do-while loop
    }//end method

    private static void addSoftware(ArrayList<ITLab> labList,ArrayList<PC> pcList,ArrayList<Software> softwareList){
        final int SIZE = pcList.size();
        final int SOFTWARESIZE = softwareList.size();
        boolean isContinue = true;
        int option = 0;
        char confirm='\0';

        do {
            PrintModule.printPCList(pcList);
            System.out.println("----------------------------------------");
            System.out.printf("Enter %d to return to PC Maintenance Module.\n", SIZE + 1);
            option = InputModule.getIntegerInput("Option:");

            if(option>0 && option<=SIZE) {
                PC ptr = pcList.get(option-1);
                boolean innerLoop = true;

                do {
                    ptr.print();
                    System.out.println();

                    PrintModule.printSoftwareList(softwareList);
                    System.out.println("----------------------------------------");
                    System.out.printf("Enter %d to return to PC Selection Page.\n", SOFTWARESIZE + 1);
                    option = InputModule.getIntegerInput("Option:");

                    try {
                        if (option > 0 && option <= SOFTWARESIZE) {
                            Software softwarePtr = softwareList.get(option - 1);
                            //if the PC already contain the software
                            if (ptr.hasSoftware(softwarePtr))
                                throw new AssertionError("The Software already present in this PC!\n");

                            //if the PC has lower ram requirement compare to software ram requirement
                            if (ptr.getRamRequirement() < softwarePtr.getRamRequirement())
                                throw new AssertionError("The PC did not have enough Ram Requirement. Minimum Ram Requirement is "+softwarePtr.getRamRequirement()+"\n");

                            //confirmation
                            System.out.println("Are you sure you want to add the Software to this PC?[Y/N]");
                            confirm = InputModule.getCharOption();
                            if (confirm == 'y' || confirm == 'Y') {
                                if (!ptr.getLabName().equals("--")) {
                                    for (ITLab lab : labList) {
                                        if (lab.getName().equals(ptr.getLabName())) {
                                            lab.getPC(ptr).addSoftware(softwarePtr);
                                            break;
                                        }
                                    }//end IT for loop
                                }
                                ptr.addSoftware(softwarePtr);
                                System.out.println("The software had been added into the software list of the PC.\n");
                            }else{
                                System.out.println("The software did not added into the software list of the PC.\n");
                            }

                        } else if (option == SOFTWARESIZE + 1) {
                            System.out.println("Returning to PC Selection Page...\n");
                            innerLoop = false;
                        } else {
                            System.out.println("Invalid Input! Please try again!");
                        }
                    }catch(AssertionError e){
                        System.out.println(e.getMessage());
                    }catch(Exception e){
                        System.out.println("Oops!An unexpected error had occur when the program is running."+e.getMessage());
                    }//end catch block
                }while(innerLoop);//end do-while loop

            }else if(option==SIZE+1){
                System.out.println("Returning to PC Maintenance Module...\n");
                isContinue = false;
            } else {
                System.out.println("Invalid Input! Please try again!");
            }
        }while(isContinue);//end do-while loop
    }//end method

    private static void deleteSoftware(ArrayList<ITLab> labList,ArrayList<PC> pcList){
        final int SIZE = pcList.size();
        boolean isContinue = true;
        int option = 0;
        char confirm = '\0';

        do {
            PrintModule.printPCList(pcList);
            System.out.println("----------------------------------------");
            System.out.printf("Enter %d to return to PC Maintenance Module.\n", SIZE + 1);
            option = InputModule.getIntegerInput("Option:");

            if(option>0&&option<=SIZE){
                PC ptr = pcList.get(option-1);
                boolean innerLoop = true;

                do {
                    ptr.print();
                    System.out.println();

                    int softwareSize = ptr.getNumSoftware();
                    System.out.println("----------------------------------------");
                    System.out.printf("Enter %d to return to PC Selection Page.\n", softwareSize + 1);
                    option = InputModule.getIntegerInput("Option:");

                    if (option > 0 && option <= softwareSize) {
                        //confirmation
                        System.out.println("Are you sure you want to remove the Software from the PC?[Y/N]");
                        confirm = InputModule.getCharOption();
                        if(confirm=='y' || confirm=='Y'){
                            if(!ptr.getLabName().equals("--")){
                                for(ITLab lab:labList){
                                    if(lab.getName().equals(ptr.getLabName())){
                                        lab.getPC(ptr).removeSoftware(option-1);
                                        break;
                                    }
                                }//end ITLab for loop
                            }
                            ptr.removeSoftware(option-1);
                            System.out.println("The software had been removed from the software list.\n");
                        }else{
                            System.out.println("The software did not removed from the software list.\n");
                        }

                    } else if (option == softwareSize + 1) {
                        System.out.println("Returning to PC Selection Page...\n");
                        innerLoop = false;
                    } else {
                        System.out.println("Invalid Input! Please try again!");
                    }
                }while(innerLoop);//end inner do-while loop

            }else if(option==SIZE+1){
                System.out.println("Returning to PC Maintenance Module...\n");
                isContinue = false;
            } else {
                System.out.println("Invalid Input! Please try again!");
            }
        }while(isContinue);//end do-while loop
    }//end method
}//end class
