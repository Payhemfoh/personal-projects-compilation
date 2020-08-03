public class Software implements Printable{
    //private variable in software 
    private String name;
    private String type;
    private double ramRequirement;
    private String expireDate;

    /**
     * default constructor of software which initialize the software
     */
    public Software(){//default constructor
        this("","",0,"");
    }

    /**
     * The overloaded constructor of software used when read and create Software when add Software into software list of PC
     * @param n name of software
     * @param t type of software
     */
    public Software(String n,String t){this(n,t,0.0,"");}

    /**
     * Copy constructor used when the software is assigned into a PC in the program
     * All fields will be copy and a new object will be created with exectly same value
     * @param obj the software to be copy
     */
    public Software(Software obj){this(obj.getName(),obj.getType(),obj.getRamRequirement(),obj.getExpireDate());}

    /**
     * The overloaded constructor used to create a new Software profile
     * @param n the name of software
     * @param t the type of software
     * @param r the ram requirement of software
     * @param e the expire data of software
     */
    public Software(String n, String t,double r, String e) {
        setName(n);
        setType(t);
        setRamRequirement(r);
        setExpireDate(e);
    }


    /**
     * The setter to set the name of software
     * @param n the name of software
     */
    public void setName(String n){
        if(n == null || n.trim().equals(""))
            name="Unknown software";
        else
            name = n;
    }
    /**
     * The setter to set the type of software
     * @param t the type of software
     */
    public void setType(String t){type = t;}
    /**
     * The setter to set the ram requirement of software
     * @param r the ram requirement of software
     */
    public void setRamRequirement(double r){
        if(r<0 || r>64){
            ramRequirement = 0;
        }
        ramRequirement = r;
    }
    /**
     * The setter to set the expire date of software
     * @param e the expire date of software
     */
    public void setExpireDate(String e){
        if(e==null || e.trim().equals(""))
            expireDate = "none";
        else
            expireDate = e;
    }

    /**
     * The getter to get the name of software
     * @return the name of software
     */
    public String getName(){return name;}
    /**
     * The getter to get the type of software
     * @return the type of software
     */
    public String getType(){return type;}
    /**
     * The getter to get the ram requirement of software
     * @return the ram requirement of software
     */
    public double getRamRequirement(){return ramRequirement;}
    /**
     * The getter to get the name of software
     * @return the name of software
     */
    public String getExpireDate(){return expireDate;}

    /**
     * This method is used to output the data of the into the file
     * @return String used to save data inside the file
     */
    @Override
    public String toString(){//format the value to store inside the file
        return (getName() + "," + getType() + "," + getRamRequirement() + "," + getExpireDate());
    }

    /**
     * This method is used to check if the object is same in terms of name and type
     * @param obj the Object to be check
     * @return the result of comparison
     */
    @Override
    public boolean equals(Object obj){//check the new or edit object is unique to existing object
        boolean isSame = false;
        
        if(!(obj instanceof Software)){
            return false;
        }

        Software temp = (Software) obj;

        if(temp.getName().equals(this.name) && temp.getType().equals(this.type)){
            isSame = true;
        }
        
        return isSame;
    }

    /**
     * this method used to print the information of software in console line-by-line
     */
    @Override
    public void print(){
        //display all the object in console
        System.out.printf("Name: %s\n",name);
        System.out.printf("Type: %s\n",type);
        System.out.printf("Ram Requirement:%.2f GB\n",this.ramRequirement);
        System.out.printf("Expire Date: %s\n",expireDate);
    }

}