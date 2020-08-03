public class ElfAlien extends Alien implements AlienSetting{
    private int damagePoint;

    /**
     * method inherit from Alien class to get the damagePoint of the object
     * @return the damagePoint of object
     */
    @Override
    public int getDamagePoint(){
        return this.damagePoint;
    }

    /**
     * method override from interface AlienSetting to set the damagePoint of object
     * @param damagePoint the damagePoint of object
     */
    @Override
    public void setDamagePoint(int damagePoint){ this.damagePoint = damagePoint*2;}

    /**
     * method override from object class to print out the information of the object when call
     * @return String of information of the object
     */
    @Override
    public String toString(){return String.format("[%-20s name=%-20s health=%-4d damage point=%-4d]",
                                                    "ElfAlien:",
                                                    this.getName(),
                                                    this.getHealth(),
                                                    this.damagePoint);}
}
