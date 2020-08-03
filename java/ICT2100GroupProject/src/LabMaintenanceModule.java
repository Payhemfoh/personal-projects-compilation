import java.util.ArrayList;

public class LabMaintenanceModule {
    /**
     * This method is the lab maintenance module which manipulate the data regarding ITLab ArrayList
     * @param labList The ArrayList of the ITLab object
     * @param pcList The ArrayList of the PC object
     */
    public static void enterITLabMaintenanceModule(ArrayList<ITLab> labList, ArrayList<PC> pcList){
        boolean isContinue = true;
        int option = 0;

        try{
            do{
                PrintModule.printLabMenu();
                option = InputModule.getIntegerInput("Option:");
                switch(option){
                    case 1:
                        //add lab
                        addLab(labList);
                        break;
                    case 2:
                        //modify lab
                        modifyLab(labList);
                        break;
                    case 3:
                        //assign pc
                        assignPC(labList,pcList);
                        break;
                    case 4:
                        //remove pc
                        removePC(labList,pcList);
                        break;
                    case 5:
                        //delete lab
                        deleteLab(labList,pcList);
                        break;
                    case 6:
                        //display lab
                        displayLabDetail(labList);
                        break;
                    case 7:
                        //exit loop and return to main menu
                        System.out.println("Returning to the Main Module...\n");
                        isContinue = false;
                        break;
                    default:
                        System.out.println("Invalid option:Please try again!");
                        isContinue = true;
                }//end switch case
            }while(isContinue);//end do-while loop
        }catch(Exception e){
            System.out.println("Unexpected Error occur during the process."+e.getMessage());
            System.exit(-1);
        } finally{
            //write data into file before exit module
            FileManagementModule.writePC(pcList);
            FileManagementModule.writeLab(labList);
        }
    }//end method

    /**
     * This method will create a new IT Lab profile and save into the list
     * @param list the list of IT Lab
     */
    private static void addLab(ArrayList<ITLab> list){
        boolean isContinue = true;
        do{
            try{
                String name = InputModule.getLabName(list);
                ITLab temp = new ITLab(name);
                list.add(temp);
                System.out.println("The IT Lab profile had been created.\n");
                isContinue = false;
            }catch(Exception e){
                System.out.println("Oops! An unexpected error had occur during the process."+e.getMessage());
            }//end catch block
        }while(isContinue);//end do-while loop
    }//end method

    /**
     * This method will let user to select a Lab profile and modify the lab profile
     * @param list the list of IT Lab
     */
    private static void modifyLab(ArrayList<ITLab> list){
        final int SIZE = list.size();
        int option = 0;
        boolean isContinue= true;

        do {
            PrintModule.printLabList(list);
            System.out.println("----------------------------------------");
            System.out.printf("Enter %d to return to IT Lab Maintenance Module.\n",SIZE+1);
            option = InputModule.getIntegerInput("Option:");

            if (option > 0 && option <= SIZE) {
                ITLab ptr = list.get(option-1);
                boolean innerLoop = true;

                do {
                    ptr.print();
                    PrintModule.printITLabEditMenu();
                    option = InputModule.getIntegerInput("Option:");

                    switch (option) {
                        case 1:
                            ptr.setName(InputModule.getLabName(list));
                            break;
                        case 2:
                            System.out.println("Returning to IT Lab Selection Page...\n");
                            innerLoop = false;
                            break;
                        default:
                            System.out.println("Invalid input, Please try again!");
                    }//end switch case
                }while(innerLoop);//end inner do-while loop

            }else if(option == SIZE+1){
                System.out.println("Returning to Lab Maintenance Module...\n");
                isContinue = false;
            } else {
                System.out.println("Invalid Input! Please try again!");
            }
        }while(isContinue);//end do-while loop
    }//end method

    /**
     * This method will let user select the lab profile and which pc to be added into the lab profile
     * @param labList the list of IT Lab
     * @param pcList  the list of PC
     */
    private static void assignPC(ArrayList<ITLab> labList,ArrayList<PC> pcList){
        final int LABSIZE = labList.size();
        final int PCSIZE = pcList.size();
        int option = 0;
        boolean isContinue= true;

        do {
            PrintModule.printLabList(labList);
            System.out.println("----------------------------------------");
            System.out.printf("Enter %d to return to IT Lab Maintenance Module.\n", LABSIZE + 1);
            option = InputModule.getIntegerInput("Option:");

            if(option>0 && option<=LABSIZE){
                ITLab labPtr = labList.get(option-1);
                boolean innerLoop = true;
                labPtr.print();
                System.out.println("---------------------------------");

                do {
                    PrintModule.printPCList(pcList);
                    System.out.println("----------------------------------------");
                    System.out.printf("Enter %d to return to IT Lab Selection Page.\n", PCSIZE + 1);
                    option = InputModule.getIntegerInput("Option:");

                    if(option>0 && option<=PCSIZE){
                        PC comPtr = pcList.get(option-1);

                        //check if the PC's labname is empty
                        if(comPtr.getLabName().equals("--")){
                            comPtr.setLabName(labPtr.getName());
                            labPtr.addPC(comPtr);
                            System.out.println("The PC had been added to the computer list.\n");
                        }else if(comPtr.getLabName().equals(labPtr.getName())){
                            System.out.println("The PC already present in the lab list!");
                            System.out.println("The PC did not added to the computer list.\n");
                        }
                        else{
                            System.out.println("The PC already present in other lab list!");
                            System.out.println("The PC did not added to the computer list.\n");
                        }

                    }else if(option==PCSIZE+1){
                        System.out.println("Returning to Lab Selection Page...\n");
                        innerLoop = false;
                    } else {
                        System.out.println("Invalid Input! Please try again!");
                    }
                }while(innerLoop);//end inner do-while loop

            }else if(option==LABSIZE+1){
                System.out.println("Returning to Lab Maintenance Module...\n");
                isContinue = false;
            } else {
                System.out.println("Invalid Input! Please try again!");
            }

        }while(isContinue);//end do-while loop
    }//end method

    /**
     * This method will let user select the lab profile and which pc to be removed from the lab profile
     * @param labList the list of IT Lab
     * @param pcList  the list of PC
     */
    private static void removePC(ArrayList<ITLab> labList,ArrayList<PC> pcList){
        final int LABSIZE = labList.size();
        int option = 0;
        boolean isContinue= true;

        do {
            PrintModule.printLabList(labList);
            System.out.println("----------------------------------------");
            System.out.printf("Enter %d to return to IT Lab Maintenance Module.\n", LABSIZE + 1);
            option = InputModule.getIntegerInput("Option:");

            if(option>0 && option<=LABSIZE){
                int index = 0;
                ITLab labPtr = labList.get(option-1);
                boolean innerLoop = true;

                do {
                    int pcSize = labPtr.getNumComputer();
                    labPtr.print();
                    System.out.println("----------------------------------------");
                    System.out.printf("Enter %d to return to IT Lab selection page.\n", pcSize + 1);
                    index = InputModule.getIntegerInput("Option:");

                    if(index>0 && index <=pcSize){
                        PC comPtr = labPtr.getPC(option-1);

                        System.out.println("Are you sure you want to remove the PC from the Lab Profile?[Y/N]");
                        char confirm = InputModule.getCharOption();
                        //confirmation
                        if (confirm == 'y' || confirm == 'Y') {
                            for (PC pc : pcList) {
                                if (comPtr.equals(pc)) {
                                    pc.setLabName("--");
                                }
                            }
                            labPtr.removePC(comPtr);
                            System.out.println("The PC had been removed from the computer list.\n");
                        }else{
                            System.out.println("The PC did not removed from the computer list.\n");
                        }
                    }else if(index==pcSize+1){
                        System.out.println("Returning to Lab Selection Page...\n");
                        innerLoop = false;
                    } else {
                        System.out.println("Invalid Input! Please try again!");
                    }

                }while(innerLoop);//end inner do-while loop
            }else if(option==LABSIZE+1){
                System.out.println("Returning to Lab Maintenance Module...\n");
                isContinue = false;
            } else {
                System.out.println("Invalid Input! Please try again!");
            }

        }while(isContinue);//end do-while loop
    }//end method

    /**
     * This method will let user select which lab profile to be removed
     * @param labList the list of IT Lab
     * @param pcList  the list of PC
     */
    private static void deleteLab(ArrayList<ITLab> labList,ArrayList<PC> pcList){
        int option = 0;
        char confirm = '\0';
        boolean isContinue = true;

        do {
            int labSize = labList.size();
            PrintModule.printLabList(labList);
            System.out.println("----------------------------------------");
            System.out.printf("Enter %d to return to IT Lab Maintenance Module.\n", labSize + 1);
            option = InputModule.getIntegerInput("Option:");

            if(option>0 && option<=labSize) {
                ITLab ptr = labList.get(option-1);

                //confirmation
                System.out.println("Are you sure you want to delete the Lab Profile?[Y/N]");
                confirm = InputModule.getCharOption();
                if (confirm == 'y' || confirm == 'Y') {
                    for(int i=0;i<ptr.getNumComputer();++i){
                        //change the lab name of pc associated in this lab
                        for(PC com : pcList){
                            if(ptr.getPC(i).equals(com)){
                                com.setLabName("--");
                            }
                        }
                    }
                    labList.remove(option - 1);
                    System.out.println("The Lab Profile had been removed from the list.\n");
                }else{
                    System.out.println("The Lab Profile did not removed from the list.\n");
                }
            }else if(option==labSize+1){
                System.out.println("Returning to Lab Maintenance Module...\n");
                isContinue = false;
            } else {
                System.out.println("Invalid Input! Please try again!");
            }

        }while(isContinue);//end do-while loop
    }//end method

    /**
     * This method will let user select which lab profile detail the user want to display
     * @param list the list of IT Lab
     */
    private static void displayLabDetail(ArrayList<ITLab> list){
        int option = 0;
        final int LABSIZE = list.size();
        boolean isContinue = true;

        do {
            PrintModule.printLabList(list);
            System.out.println("----------------------------------------");
            System.out.printf("Enter %d to return to IT Lab Maintenance Module.\n", LABSIZE + 1);
            option = InputModule.getIntegerInput("Option:");

            if(option>0 && option<=LABSIZE){
                list.get(option-1).print();
                System.out.println();
            }else if(option==LABSIZE+1){
                System.out.println("Returning to Lab Maintenance Module...\n");
                isContinue = false;
            } else {
                System.out.println("Invalid Input! Please try again!");
            }

        }while(isContinue);//end do-while loop
    }//end method
}//end class
