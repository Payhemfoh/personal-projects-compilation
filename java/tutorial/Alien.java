public abstract class Alien {
    private int health;
    private String name;

    /**
     * default constructor
     */
    public Alien(){
        this("",0);
    }

    /**
     * overloaded constructor to set the name and hp of Alien object
     * @param n name
     * @param hp health point of Alien object
     */
    public Alien(String n,int hp){
        setName(n);
        setHealth(hp);
    }

    /*
        getter
     */
    public int getHealth(){return this.health;}
    public String getName(){return this.name;}

    /**
     * setter to set the health of the Alien object in range of 0 to 100
     * @param health the health of Alien object to be set
     */
    public void setHealth(int health){
        if(health<0 || health>100)
            this.health=0;
        else
            this.health = health;
    }

    /**
     * setter to set the name of Alien object(provided validation)
     * @param name the name of Alien object
     */
    public void setName(String name){
        if(name==null||name.trim().equals("")) {
            this.name = "Unknown name";
        }
        else{
            this.name = name;
        }
    }

    /**
     * method to get the damage point of the object
     * @return
     */
    public abstract int getDamagePoint();

    @Override
    public String toString(){
        return String.format("[Alien: name=%-20s health=%-4d]",this.name,this.health);
    }
}