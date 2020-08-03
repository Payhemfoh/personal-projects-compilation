import java.util.ArrayList;

public class LabManagementSystem{
    /**
     * This is the main method which the program will start from this method
     * @param args the argument list from the console
     */
    public static void main(String[] args){
        ArrayList<ITLab> labList = null;
        ArrayList<PC> computerList = null;
        ArrayList<Software> softwareList = null;

        try {
            //read data from file
            softwareList = FileManagementModule.readSoftware();
            computerList = FileManagementModule.readPC(softwareList);
            labList = FileManagementModule.readLab(computerList);

            if (labList == null || computerList == null || softwareList == null)
                throw new NullPointerException();

            entermainModule(labList, computerList, softwareList);

        }//end try block
        catch(NullPointerException e){
            System.out.println("Failed to read data into the ArrayList.");
            System.exit(-1);

        } catch(Exception e){
            System.out.println("Unexpected Error occur during the process."+e.getMessage());
        }//end catch block
        finally{
            //write data into file before the program is end
            FileManagementModule.writeSoftware(softwareList);
            FileManagementModule.writePC(computerList);
            FileManagementModule.writeLab(labList);
        }
    }//end method

    /**
     * This method will decide which module will the program entered next from the main method
     * @param labList the Array List of the ITLab object
     * @param computerList the Array List of the PC object
     * @param softwareList the Array List of the Software object
     */
    public static void entermainModule(ArrayList<ITLab> labList,ArrayList<PC> computerList,ArrayList<Software> softwareList){
        boolean isContinue = true;
        int option = 0;

        System.out.println("Welcome to Lab Management System");
        //main menu loop
        do{
            PrintModule.printMainMenu();
            option = InputModule.getIntegerInput("Option:");

            switch(option){
                case 1:
                    LabMaintenanceModule.enterITLabMaintenanceModule(labList,computerList);
                    break;
                case 2:
                    //user can only enter when have at least one software at the list
                    if(softwareList.size()<1){
                        System.out.println("You can only enter this module if you have more than one software!");
                        System.out.println("Please add your software at the Software Maintenance Module!");
                        System.out.println();
                    }else
                        PCMaintenanceModule.enterPCMaintenanceModule(labList,computerList,softwareList);
                    break;
                case 3:
                    SoftwareMaintenanceModule.enterSoftwareMaintenanceModule(labList,computerList,softwareList);
                    break;
                case 4:
                    SearchModule.enterSearchModule(labList,computerList,softwareList);
                    break;
                case 5:
                    HTMLExportationModule.export(labList,computerList,softwareList);
                    break;
                case 6:
                    isContinue = false;
                    break;
                default:
                    System.out.println("Invalid option:Please try again!");
            }//end switch case

        }while(isContinue);//end do-while loop to repeat the whole program.
    }//end method
}//end class
