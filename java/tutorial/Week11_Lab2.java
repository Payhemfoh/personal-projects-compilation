import org.jetbrains.annotations.NotNull;

import java.util.Scanner;

class TestPlayer {
    public static void main(String args[]){
       Weapon weaponList[] = {
               new Weapon("Fire Sword",5),
               new Weapon("Water Sword",3),
               new Weapon("Secret Sword",4),
               new Weapon("Stone Hammer",6),
               new Weapon("Fire Lance",10)
       };

        Player player=null;
        int weaponNumber=0;

        //get back weapon number selected by user from list
        weaponNumber = showWeaponList(weaponList);

        player = createPlayer(weaponNumber,weaponList);

        System.out.println(player);

        //change player weapon
        weaponNumber = showWeaponList(weaponList);
        player.setWeapon(weaponList[weaponNumber-1]);

        //redisplay player status
        System.out.println(player);
    }

    public static int showWeaponList(Weapon[] list){
        int count=0;
        Scanner sc = new Scanner(System.in);

        System.out.printf("%-3s%-40s%-4s\n","ID","Weapon Name","Damage");
        System.out.println("-----------------------------------------");
        for(int i=0;i<list.length;i++){
            System.out.printf("%-3d%-40s%-4d\n",i+1,list[i].getName(),list[i].getAttack());
        }
        System.out.print("Choose Your Weapon:");
        count = sc.nextInt();

        while(count<1||count>list.length){
            System.out.print("Invalid Weapon Number! Enter again:");
            count = sc.nextInt();
        }

        return count;
    }

    public static @NotNull
    Player createPlayer(int no, Weapon[] list){
        Scanner sc = new Scanner(System.in);
        Weapon w = list[no-1];
        System.out.print("Enter Player Name:");
        String name=sc.nextLine();

        while(name.trim().equals("")){
            System.out.print("The name should not be empty!Please try again:");
            name = sc.nextLine();
        }

        Player player = new Player(name,w);
        return player;
    }
}

class Weapon{
    private String name;
    private int attack;

    //overloaded constructor
    public Weapon(String n,int a){
        name =n;
        attack =a;
    }

    //getter
    public int getAttack(){return attack;}
    public String getName(){return name;}

    //setter
    public void setName(String n){
        if(n.trim().equals("")||n==null)
            name="Unknown Weapon";
        else
            name =n;
    }
    public void setAttack(int a){
        if(a<=0)
            attack=1;
        else
            attack = a;
    }

    //toString
    @Override
    public String toString(){return "Name:"+name+" \tAttack:"+attack;}
}


class Player{
    private String name;
    private Weapon weapon;

    //constructor
    public Player(String n,Weapon w){
        name =n;
        weapon =w;
    }

    //getter
    public String getName(){return name;}
    public Weapon getWeapon(){return weapon;}

    //setter
    public void setName(String n){
        if(n.trim().equals("")||n==null)
            name="Player";
        else
            name =n;
    }
    public void setWeapon(Weapon w){
        if(w==null)
            weapon=new Weapon("Unknown Weapon",1);
        else
            weapon = w;
    }

    //toString
    @Override
    public String toString(){return "Name:"+name+"\nWeapon:"+weapon;}
}