public class AlienDriver{
    public static void main(String[] args){
        final int SIZE = 10;
        Alien alienList[] = new Alien[SIZE];

        for(int i=0;i<SIZE;++i){
            int rand = (int)(Math.random()*10);
            if(rand<=6){
                alienList[i] = new DinosaurAlien();
                alienList[i].setName("Dinosaur Alien "+(i+1));
                alienList[i].setHealth(70);
                ((DinosaurAlien)alienList[i]).setDamagePoint(50);
            }
            else{
                alienList[i] = new ElfAlien();
                alienList[i].setName("Elf Alien "+(i+1));
                alienList[i].setHealth(30);
                ((ElfAlien)alienList[i]).setDamagePoint(80);
            }
        }
        for(Alien x : alienList){
            System.out.println(x);
        }
        System.out.println();

        printTable(alienList,SIZE);

    }

    /**
     * method to summaries the Alien Object and print out the result
     * @param list the Alien Object list to be summaries
     * @param size the number of object in the list
     */
    public static void printTable(Alien[] list,int size){
        int numDinoAlien = 0, numElfAlien = 0;
        int totalDinoAttack = 0, totalElfAttack = 0;

        for(int i=0;i<size;++i){
            if(list[i] instanceof DinosaurAlien){
                ++numDinoAlien;
                totalDinoAttack += ((DinosaurAlien)list[i]).getDamagePoint();
            }else if(list[i] instanceof ElfAlien){
                ++numElfAlien;
                totalElfAttack += list[i].getDamagePoint();
            }
        }

        System.out.printf("%d DinosaurAlien found with total damage point %d\n",numDinoAlien,totalDinoAttack);
        System.out.printf("%d ElfAlien found with total damage point %d\n",numElfAlien,totalElfAttack);
    }
}