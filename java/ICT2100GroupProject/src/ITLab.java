public class ITLab implements Printable, PCModifier {
    private String name;
    private PC computerList[];
    private int numComputer;

    /**
     * Overloaded constructor which used when create new lab profile
     * @param name  the name of the IT Lab
     */
    public ITLab(String name){
        setName(name);
        computerList = new PC[COMPUTERLISTSIZE];
    }

    /**
     * getter which return the name of the IT Lab
     * @return the name of the IT Lab
     */
    public String getName(){return this.name;}

    /**
     * getter to return the number of computer in the list
     * @return the number of computer in the list
     */
    @Override
    public int getNumComputer(){return this.numComputer;}

    /**
     * setter to set the name of the IT Lab
     * @param name the name of the IT Lab
     */
    public void setName(String name){
        if(name == null || name.trim().equals(""))
            this.name = "Unknown IT Lab";
        else
            this.name = name;
    }//end method

    /**
     * This method will print the computer list in a table format
     */
    @Override
    public void printComputerList(){
        System.out.printf("%-6s|%-30s|%-30s\n","Index","Computer Name","IPv4");
        System.out.println("----------------------------------------\n");
        for(int i=0;i<numComputer;++i){
            System.out.printf("%-6d|%-30s|%-30s\n",i+1,computerList[i].getName(),computerList[i].getIp());
        }
    }//end method

    /**
     * This method is used to add a PC into the computer list
     * @param computer the PC to be added into the list
     */
    @Override
    public void addPC(PC computer){

        try {
            //if the list already full, display error message
            if (numComputer >= COMPUTERLISTSIZE)
                throw (new ArrayIndexOutOfBoundsException());

            //check if the computer to be added is null value
            if (computer==null)
                throw (new NullPointerException());

            //modify the labName of the PC object
            computer.setLabName(this.name);

            //deep copy of the computer into the arrayList
            //add 1 to the number of computer in list after copy
            computerList[numComputer++] = new PC(computer);

        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Oops!The number of computer in the Lab already reached the maximum value\n");

        }catch(NullPointerException e){
            System.out.println("Oops!The computer didn't assign to any value.\n");

        }catch(Exception e){
            System.out.println(e.getMessage());
        }//end catch block
    }//end method

    /**
     * This method will compare the PC object and the pc in the list and remove when the pc is match
     * @param obj The PC object to be removed from the list
     */
    @Override
    public void removePC(PC obj){
        int index =0;

        for(int i=0;i<numComputer;++i){
            if(computerList[i].equals(obj)){
                index = i;
            }
        }

        for(int i=index;i<numComputer-1;++i){
            computerList[i] = new PC(computerList[i+1]);
        }
        computerList[numComputer] = null;
        --numComputer;
    }//end method

    /**
     * This method will remove the pc from the computer list based on the index input
     * @param index the index of pc to be removed in the computer list
     */
    @Override
    public void removePC(int index){
        for(int i=index;i<numComputer-1;++i){
            computerList[i] = computerList[i+1];
        }
        computerList[numComputer] = null;
        --numComputer;
    }//end method

    /**
     * This method will search through the list and return the PC object in the list if found
     * @param pc the PC object to be search
     * @return the PC object in the list which is match to the parameter
     */
    @Override
    public PC getPC(PC pc) {
        for(int i=0;i<numComputer;++i){
            if(pc.equals(computerList[i]))
                return computerList[i];
        }

        return null;
    }//end method

    /**
     * This method will return the PC object in the list based on the index
     * @param index the index of PC object in the list
     * @return the PC object in the list
     */
    @Override
    public PC getPC(int index) {
        return computerList[index];
    }

    /**
     * Check if the PC object is in the computer list
     * @param obj the PC object to be checked
     * @return the search result of the PC object
     */
    @Override
    public boolean hasPC(PC obj){
        //check if the computer already exists in the list
        for(int i=0;i<numComputer;++i){
            if(obj.equals(computerList[i]))
                return true;
        }

        return false;
    }//end method

    /**
     * This method search the PC object in the computer list and return the position of the object in the list
     * @param obj the PC object to be searched
     * @return the index of the object in the list
     */
    @Override
    public int getComputerPos(PC obj){
        for(int i=0;i<numComputer;++i){
            if(obj.equals(computerList[i]))
                return i;
        }
        return -1;
    }//end method

    /**
     * This method will print the information of this object to the console
     */
    @Override
    public void print(){
        System.out.printf("Name:%s\n",this.name);
        System.out.printf("No.Computer:%d\n",this.numComputer);
        System.out.println("----------------------------------------");
        System.out.printf("%-3s|%-30s|%-30s\n","No.","ComputerName","IPv4");
        System.out.println("----------------------------------------");

        for(int i=0;i<numComputer;++i){
            System.out.printf("%-3d|%-30s|%-30s\n",i+1,computerList[i].getName(),computerList[i].getIp());
        }//end for loop
        System.out.println();
    }//end method

    /**
     * This method is used to output the data of the into the file
     * @return String used to save data inside the file
     */
    @Override
    public String toString(){
        return String.format("%s,%d",this.name,this.numComputer);
    }//end method

    /**
     * This method is used to check if the object is same in terms of name
     * @param obj the Object to be check
     * @return the result of comparison
     */
    @Override
    public boolean equals(Object obj){
        if(!(obj instanceof ITLab))
            return false;

        boolean result = false;
        ITLab temp = (ITLab) obj;

        if(temp.getName().equals(this.name)){
            result = true;
        }
        return result;
    }//end method
}//end class
