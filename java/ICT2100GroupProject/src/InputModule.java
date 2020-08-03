import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class InputModule {
    /**
     * This method is used to get the string input from the user
     * and the input is then validated so that the user did not enter empty string
     * @param prompt the prompt text to be displayed to the user
     * @return the input of the user which is validated
     */
    public static String getStringInput(String prompt){
        boolean isValid = false;
        String input ="";

        Scanner sc = new Scanner(System.in);

        //loop until the input is valid
        do{
            try {
                System.out.print(prompt);
                input = sc.nextLine().trim();
                System.out.println();
                //check so that the user did not enter empty string
                if (input.equals(""))
                    throw new InputMismatchException();
                else
                    isValid = true;
            }//end try block

            catch(InputMismatchException e){
                System.out.println("Invalid input, please try again!\n");
                isValid = false;
            }
            catch(Exception e){
                System.out.println("An unexpected error had occur during the process!\n"+e.getMessage()+"\n");
                isValid = false;
            }//end catch block
        }while(!isValid);//end do-while loop

        return input;
    }//end method

    /**
     * This method is used to get the double input from the user
     * and the input is then validated so that the user did not enter empty string and alphabets
     * @param prompt the prompt text to be displayed to the user
     * @return the input of the user which is validated
     */
    public static double getDoubleInput(String prompt){
        boolean isValid = false;
        double input = 0.0;
        double stringInput = 0.0;
        Scanner sc = new Scanner(System.in);

        //loop until the input is valid
        while(!isValid){
            try {
                System.out.print(prompt);
                stringInput = Double.parseDouble(sc.nextLine().trim());
                System.out.println();
                isValid = true;
            }
            catch(InputMismatchException | NumberFormatException e){
                System.out.println("Invalid input, Please try again!\n");
                isValid = false;
            }
            catch(Exception e){
                System.out.println("Oops! An unexpected error had occur during the process."+e.getMessage()+"\n");
                isValid = false;
            }
        }
        //to get the 2 decimal places input
        input = Double.parseDouble(String.format("%.2f",stringInput));
        return input;
    }//end method

    /**
     * This method is used to get the integer input from the user
     * and the input is then validated so that the user did not enter empty string, alphabets and floating point
     * @param prompt the prompt text to be displayed to the user
     * @return the input of the user which is validated
     */
    public static int getIntegerInput(String prompt){
        boolean isValid = false;
        int input = 0;
        Scanner sc = new Scanner(System.in);

        while(!isValid){
            try {
                System.out.print(prompt);
                input = Integer.parseInt(sc.nextLine().trim());
                System.out.println();
                isValid = true;
            }//end try block

            catch(InputMismatchException | NumberFormatException e){
                System.out.println("Invalid input, Please try again!\n");
                isValid = false;
            }
            catch(Exception e){
                System.out.println("Oops! An unexpected error had occur during the process."+e.getMessage()+"\n");
                isValid = false;
            }//end catch block
        }//end while loop
        return input;
    }//end method

    /**
     * This method is used to get the software type input from the user
     * the menu is displayed so that the user can select which software type is needed to reduce the type error
     * the input will loop until a valid input is entered
     * @return the software type which is validated
     */
    public static String getSoftwareTypeInput(){
        int option = 0;
        String result = "";
        boolean isValid = false;

        do {
            PrintModule.printSoftwareTypeSelectMenu();
            option = getIntegerInput("Option:");
            switch (option) {
                case 1:
                    result = "Proprietary";
                    isValid = true;
                    break;
                case 2:
                    result = "Shareware";
                    isValid = true;
                    break;
                case 3:
                    result = "Freeware";
                    isValid = true;
                    break;
                default:
                    System.out.println("Invalid input Please try again!\n");
                    isValid = false;
            }//end switch case
        }while(!isValid);//end do-while loop

        return result;
    }//end method

    /**
     * This method is used to get the IPv4 input from the user
     * the sample is shown to the user so that the user know how is the valid input
     * The input is checked so that it can be divided into 4 blocks with valid digit after split with "."
     * the input will loop until a valid input is entered
     * @return the IPv4 object which is created after the validated
     */
    public static IPv4 getIPv4Input(){
        final int SIZE = 4;
        int blockValue = 0;
        boolean isValid = true;
        int[] bytes = new int[SIZE];
        String[] blocks = null;

        do {
            try {
                String ip = getStringInput("Please enter the IP address [xxx.xxx.xxx.xxx](xxx indicate range of 0-255) :");
                blocks = ip.split("\\.");

                if (blocks.length != SIZE)
                    throw new InputMismatchException();

                for (int i = 0; i < SIZE; ++i) {
                    blockValue = Integer.parseInt(blocks[i]);

                    if (blockValue < 0 || blockValue > 255)
                        throw new InputMismatchException();

                    bytes[i] = blockValue;
                    isValid = true;
                }//end for loop to check the valid integer
            }//end try block

            catch (InputMismatchException | NumberFormatException e) {
                System.out.println("Invalid format of IP address! Please try again!\n");
                isValid = false;
            }catch (Exception e){
                System.out.println("Oops! An unexpected error occur during the process. "+e.getMessage()+"\n");
                isValid = false;
            }//end catch block
        }while(!isValid);//end do-while loop

        return new IPv4(bytes[0],bytes[1],bytes[2],bytes[3]);
    }//end method

    /**
     * This method is used to get the Character option from the user
     * mainly for the confirmation of edit and delete
     * input is validated so that no empty input or space will be return
     * @return char input used for confirmation of edit and delete
     */
    public static char getCharOption(){
        Scanner sc = new Scanner(System.in);
        boolean isValid = false;
        char input = '\u0000';

        while(!isValid){
            try {
                System.out.print("Option:");
                input = sc.nextLine().trim().charAt(0);
                isValid = true;
            }
            catch(InputMismatchException | StringIndexOutOfBoundsException e){
                System.out.println("Invalid input, Please try again!\n");
                isValid = false;
            }
            catch(Exception e){
                System.out.println("Oops! An unexpected error occur during the process. "+e.getMessage()+"\n");
                isValid = false;
            }//end catch block
        }//end while loop
        return input;
    }//end method

    /**
     * This method is used to get the pc type input from the user
     * the menu is displayed so that the user can select which pc type is needed to reduce the type error
     * the input will loop until a valid input is entered
     * @return the pc type which is validated
     */
    public static String getPCTypeInput(){
        int option = 0;
        String result = "";

        PrintModule.printPCTypeSelectMenu();
        option = getIntegerInput("Option:");
        switch (option) {
            case 1:
                result = "Desktop";
                break;
            case 2:
                result = "Laptop";
                break;
            default:
                System.out.println("Invalid input Please try again!\n");
        }
        return result;
    }

    /**
     * This method is used to get the ram input from the user
     * The ram input is validated so that the user cannot enter lower than the minimum value and higher then maximum value
     * the input will loop until a valid input is entered
     * @return the ram input by the user which is validated
     */
    public static double getRamInput(String prompt){
        final double LOWEST = 0.01, HIGHEST = 64.00;
        boolean isValid = false;
        double ram = 0.0;
        do {
            try {
                ram = getDoubleInput(prompt);

                if(ram<LOWEST || ram>HIGHEST)
                    throw new InputMismatchException();

                isValid = true;
            }catch(InputMismatchException | NumberFormatException e){
                System.out.printf("Invalid Input! The ram should be in range of [%.2f - %.2f]! Please try again!\n"
                                    ,LOWEST,HIGHEST);
                isValid = false;
            }
            catch(Exception e){
                System.out.println("Oops! An unexpected error had occur during the process."+e.getMessage()+"\n");
                isValid = false;
            }//end catch block

        }while(!isValid);//end do-while loop

        return ram;
    }//end method

    /**
     * This method is used to get the year input from the user
     * The year input is validated so that the user must enter 4 digit value for the year input
     * the input will loop until a valid input is entered
     * @return the year entered which is validated
     */
    public static int getYearInput(String prompt){
        int year = 0;
        boolean isValid = false;

        do {
            try {
                year = InputModule.getIntegerInput(prompt);

                if(year<1000 || year>9999)
                    throw new InputMismatchException();

                isValid = true;
            }catch(InputMismatchException e){
                System.out.println("Invalid Input! The year should be in range of [1000 - 9999]! Please try again!\n");
                isValid = false;
            }
            catch(Exception e){
                System.out.println("Oops! An unexpected error had occur during the process."+e.getMessage()+"\n");
                isValid = false;
            }
        }while(!isValid);//end do-while loop

        return year;
    }//end method

    /**
     * This method is used to get the date input from the user
     * The year input is validated so that the user must enter 4 digit value for the year input
     * The month input is fixed to 1 until 12
     * The day input is validated based on the month
     * the input will loop until a valid input is entered
     * @return the String of the data input
     */
    public static String getDateInput(){
        boolean isValid = false;

        int year = getYearInput("Enter year of software expired:");

        int month = 0,day = 0;

        do {
            month = InputModule.getIntegerInput("Enter month of software expired[1-12]:");
            if(month<1||month>12) {
                System.out.println("Invalid Input! The month should in range of [1 - 12]! Please try again!\n");
                isValid = false;
            }else{
                isValid = true;
            }
        }while(!isValid);

        do {
            day = InputModule.getIntegerInput("Enter day of software expired:");
            if(MonthConverter.checkDay(day,month)){
                isValid = true;
            }else{
                System.out.println("Invalid Input! There are no day "+day+" in month "+MonthConverter.convertMonth(month)+"\n");
                isValid = false;
            }
        }while(!isValid);

        return day + "-" + MonthConverter.convertMonth(month)+ "-" + year;
    }

    /**
     * This method is used to get the name input for lab from the user
     * The input is then checked with the list so that there are no duplication of name
     * the input will loop until a valid input is entered
     * @return the name of lab which is validated
     */
    public static String getLabName(ArrayList<ITLab> list){
        boolean isValid = false;

        String name = "";
        do {
            isValid = true;
            name = InputModule.getStringInput("Enter IT Lab Name:");
            for(ITLab lab : list){
                if(lab.getName().equals(name)){
                    System.out.println("The IT Lab already present in the IT Lab list!\n");
                    isValid = false;
                    break;
                }//end if the lab name is equals to the name input
            }//end ITLab for loop
        }while(!isValid);

        return name;
    }//end method

    /**
     * This method is used to get the name input for pc from the user
     * The input is then checked with the list so that there are no duplication of name
     * the input will loop until a valid input is entered
     * @return the name of pc which is validated
     */
    public static String getPCName(ArrayList<PC> list){
        boolean isValid = false;

        String name = "";
        do {
            isValid = true;
            name = InputModule.getStringInput("Enter PC Name:");
            for(PC pc : list){
                if(pc.getName().equals(name)){
                    System.out.println("The PC already present in the PC list!\n");
                    isValid = false;
                    break;
                }//end if the pc name is equals to the name input
            }//end PC for loop
        }while(!isValid);

        return name;
    }//end method

    /**
     * This method is used to get the name input for software from the user
     * The input is then checked with the list so that there are no duplication of name
     * the input will loop until a valid input is entered
     * @return the name of software which is validated
     */
    public static String getSoftwareName(ArrayList<Software> list){
        boolean isValid = false;

        String name = "";
        do {
            isValid = true;
            name = InputModule.getStringInput("Enter Software Name:");
            for(Software software : list){
                if(software.getName().equals(name)){
                    System.out.println("The Software already present in the software list!\n");
                    isValid = false;
                    break;
                }//end if the software name is equals to the name input
            }//end Software for loop
        }while(!isValid);

        return name;
    }//end method
}//end class
