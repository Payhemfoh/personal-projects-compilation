class Monster {

    //instance members OR non-static members
    private String name;
    private String skill;
    private int hp;
    public static int count=0;//static member OR class member

    public Monster(){
        count++;
    }

    public String getName(){return name;}
    public void setName(String n){name =n;}
}

class TestMonster{
    public static void main(String[] args){
        Monster critter = new Monster();    //count = 1

        critter.setName("Critter");
        System.out.println(critter.getName());  //Critter
        System.out.println(critter.count);//1
        System.out.println(Monster.count);//1

    }
}