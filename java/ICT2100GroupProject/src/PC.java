import java.util.ArrayList;

public class PC implements Printable, SoftwareModifier {
    private String name;
    private IPv4 ip;
    private String computerType;
    private int yearManufacture;
    private double ramRequirement;
    private String labName;
    private ArrayList<Software> softwareList;

    /**
     * Copy constructor to create a new object with same value as the parameter object
     * This constructor is mainly used in the add computer in the ITLab class
     * @param obj the object to be copy
     */
    public PC(PC obj){
        this(obj.getName(),obj.getIp(),obj.getComputerType(),
                obj.getYearManufacture(),obj.getRamRequirement(),obj.getLabName());
    }//end method

    /**
     * This is the overloaded constructor used to create a new PC object
     * @param n the name of the PC
     * @param ip the IPv4 address of the PC
     * @param ct the computer type of the PC
     * @param ym the year of manufacture of the PC
     * @param r the ram requirement of the PC
     */
    public PC (String n, IPv4 ip, String ct, int ym, double r){
        this(n,ip,ct,ym,r,"");
    }

    /**
     * This is the overloaded constructor used to create new PC which is mainly used when the data file is read
     * @param n the name of PC
     * @param ip the IPv4 address of the PC
     */
    public PC (String n,String ip){
        this.setName(n);
        this.setIp(ip);
        this.softwareList = new ArrayList<Software>();
    }//end method

    /**
     * This is the overloaded which contain all of the private fields of the PC object
     * @param n the name of the PC
     * @param ip the IPv4 address of the PC
     * @param ct the computer type of the PC
     * @param ym the year of manufacture of the PC
     * @param r the ram requirement of the PC
     * @param lb the lab name of the PC
     */
    public PC (String n, IPv4 ip, String ct, int ym, double r, String lb){
        this.setName(n);
        this.setIp(ip);
        this.setComputerType(ct);
        this.setYearManufacture(ym);
        this.setRamRequirement(r);
        this.setLabName(lb);
        this.softwareList = new ArrayList<Software>();
    }//end method

    /**
     * The setter to set the name of PC
     * @param n the name of PC
     */
    public void setName(String n){
        if(n==null || n.trim().equals(""))
            this.name = "unknown name";
        else
            this.name = n;
    }//end method

    /**
     * The setter to set the Ip of PC
     * @param ip the IP of PC (IPv4 object)
     */
    public void setIp(IPv4 ip){
        if(ip==null)
            this.ip = new IPv4();
        else
            this.ip = ip;
    }//end method
    /**
     * The setter to set the Ip of PC
     * @param ip the IP of PC (String type)
     */
    public void setIp(String ip){
        if(ip == null || ip.trim().equals(""))
            this.ip = new IPv4();
        else
            this.ip = new IPv4(ip);
    }//end method

    /**
     * The setter to set the computer type of PC
     * @param ct the computer type of PC
     */
    public void setComputerType(String ct){
        if(ct==null || ct.trim().equals(""))
            this.computerType="--";
        else
            this.computerType = ct;
    }//end method

    /**
     * The setter to set the year of manufacture of PC
     * The year of manufacture will always be in 4 digits
     * @param ym the year of manufacture of PC
     */
    public void setYearManufacture(int ym){
        if(ym<1000 || ym>9999)
            this.yearManufacture = 1000;
        else
            this.yearManufacture = ym;
    }//end method

    /**
     * The setter to set the ram requirement of PC
     * The ram requirement of PC should always between 0.01 and 64
     * @param r the ram requirement of PC
     */
    public void setRamRequirement(double r){
        if(r<0.01 || r>64)
            this.ramRequirement = 0;
        else
            this.ramRequirement = r;
    }//end method

    /**
     * The setter to set the lab name of PC
     * The lab name should not be set by user but only the program
     * @param lb the lab name of the PC
     */
    public void setLabName(String lb){
        if(lb==null || lb.trim().equals(""))
            this.labName = "--";
        else
            this.labName = lb;
    }//end method

    /**
     * The getter to get the name of PC
     * @return the name of PC
     */
    public String getName(){ return name; }
    /**
     * The getter to get the ip of PC
     * @return the ip of PC
     */
    public IPv4 getIp(){ return ip; }
    /**
     * The getter to get the computer type of PC
     * @return the computer type of PC
     */
    public String getComputerType(){ return computerType; }
    /**
     * The getter to get the year manufacture of PC
     * @return the year manufacture of PC
     */
    public int getYearManufacture(){ return yearManufacture; }
    /**
     * The getter to get the ram requirement of PC
     * @return the ram requirement of PC
     */
    public double getRamRequirement(){ return ramRequirement; }
    /**
     * The getter to get the lab name of PC
     * @return the lab name of PC
     */
    public String getLabName(){ return labName; }

    /**
     * This method is used to print the software in the software list of the PC
     */
    @Override
    public void printSoftwareList() {
        int size = softwareList.size();
        System.out.printf("%-6s|%-30s\n","Index","Software");
        System.out.println("------------------------------");

        for(int i=0;i<size;++i){
            System.out.printf("%-6d|%-30s\n",i+1,softwareList.get(i).getName());
        }
    }//end method

    /**
     * This method is used to add the software into the software list of the PC
     * @param s the software to be added into the software list
     */
    @Override
    public void addSoftware(Software s){
        softwareList.add(new Software(s));
    }//end method

    /**
     * This method is used to remove the software from the software list of the PC
     * @param s the software to be remove from the software list
     */
    @Override
    public void removeSoftware(Software s){
        softwareList.remove(s);
    }//end method

    /**
     * This method is used to remove the software from the software list of the PC
     * @param index the index of the software to be removed in the software list
     */
    @Override
    public void removeSoftware(int index) {
        softwareList.remove(index);
    }//end method

    /**
     * This method is used to check if the software is present in the software list of the PC
     * @param s the software to be found in the software list
     */
    @Override
    public boolean hasSoftware(Software s){
        for (Software software : softwareList) {
            if (s.equals(software)) {
                return true;
            }
        }//end Software for loop

        return false;
    }//end method

    /**
     * This method is used to get the software in the software list by comparing the software
     * @param s the software to be found and return in the software list
     * @return the software match in the software list
     */
    @Override
    public Software getSoftware(Software s) {
        int index = -1;
        final int size =softwareList.size();

        for(int i=0;i<size;++i){
            if(softwareList.get(i).equals(s)){
                return softwareList.get(i);
            }
        }//end Software for loop

        return null;
    }//end method

    /**
     * This method is used to get the software in the software list by using the index of software
     * @param index the index of the software in the software list
     * @return the software in the software list
     */
    @Override
    public Software getSoftware(int index) {
        return softwareList.get(index);
    }//end method

    /**
     * This method is used to get the number of software in the software list of the PC
     * @return the number of software in the list
     */
    @Override
    public int getNumSoftware() {
        return softwareList.size();
    }//end method

    /**
     * This method is used to output the data of the into the file
     * @return String used to save data inside the file
     */
    @Override
    public String toString(){
        return (getName() + "," + getIp().toString() + "," + getComputerType() + "," +
                getYearManufacture() + "," + getRamRequirement() + "," + getLabName());
    }//end method

    /**
     * This method is used to check if the object is same in terms of name and IPv4
     * @param obj the Object to be check
     * @return the result of comparison
     */
    @Override
    public boolean equals(Object obj){
        if(!(obj instanceof PC)){
            return false;
        }

        boolean result = false;

        PC temp = (PC) obj;
        if(temp.getName().equals(this.name)||temp.getIp().toString().equals(this.ip.toString())){
            result = true;
        }

        return result;
    }//end method

    /**
     * This method will print the information of this object to the console
     */
    @Override
    public void print(){
        System.out.println("Name:"+this.name);
        System.out.println("IPv4:"+this.ip);
        System.out.println("Computer type:"+this.computerType);
        System.out.println("Year of manufacture:"+this.yearManufacture);
        System.out.println("Ram requirement:"+this.ramRequirement);

        if(labName.equals("--"))
            System.out.println("This pc is not under any of the IT Lab.");
        else
            System.out.println("Lab name:"+this.labName);

        System.out.println("Software List:");
        System.out.printf("%-6s|%-30s|%-10s\n","Index","Software Name","Ram Req.(GB)");
        System.out.println("----------------------------------------");

        for(int i=0;i<softwareList.size();++i){
            System.out.printf("%-6d|%-30s|%-10.2f\n",i+1,softwareList.get(i).getName(),softwareList.get(i).getRamRequirement());
        }//end for loop
    }//end method
}//end class

