//import java.lang.Math;

public class Week11_Lab7 {
    public static void main(String[] args){
        //10 new character
        Character player[] = new Character[10];

        //create player randomly
        for(int i=0;i<player.length;++i){
            int random =(int) (Math.random() * 5);

            //Late binding (Polymorphism)
            if(random<4){
                player[i] = new Monster("Monster"+i,"Weapon"+i);
            }
            else
                player[i] = new Boss("Boss"+i,2);
        }

        //display all attack
        for(int i=0;i<player.length;++i){
            player[i].attack();

            //check type
            if(player[i] instanceof Boss){
                ((Boss)player[i]).healHP();
            }
        }
    }
}

abstract class Character{
    protected String name;

    public Character(String n){name = n;}

    public abstract void attack();  //abstract method
}//end of abstract class

class Monster extends Character{
    private String weapon;

    public Monster(String name,String weapon){
        super(name);
        this.weapon = weapon;
    }

    @Override
    public void attack(){
        System.out.println("The monster ["+name+"] had attacked you with "+ weapon);
    }
}

class Boss extends Character implements SpecialActionListener{
    private int attackRate;

    public Boss(String name,int ar){
        super(name);
        attackRate = ar;
    }

    @Override
    public void attack(){
        System.out.println("The boss ["+name+"] had attacked you with super weapon X "+attackRate+" damage rate!");
    }

    @Override
    public void healHP(){
        System.out.println("The boss drink a MegaPotion and restore 100% hp");
    }
}

interface SpecialActionListener{
    public void healHP();
}