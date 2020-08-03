import java.util.Random;
import java.util.Scanner;

public class Treasure {
    final int[] POINTRANGE = {10,30,50};
    private int posX;
    private int posY;
    private int point;

    Treasure(){
        Random r = new Random();
        this.posX = r.nextInt(100)+1;
        this.posY = r.nextInt(100)+1;
        int rand = r.nextInt(3);
        point = POINTRANGE[rand];
    }

    public int getPosX(){return this.posX;}
    public int getPosY(){return this.posY;}
    public int getPoint(){return this.point;}


    @Override
    public String toString(){return ""+posX+"\t"+posY+"\n";}
}

class Player2{
    private String name;
    private int posX;
    private int posY;
    private int score;

    public Player2(String name){
        this.name = name;
    }

    public String getName(){return this.name;}

    public int getPosX() { return posX; }

    public int getPosY() {
        return posY;
    }

    public int getScore() {
        return score;
    }

    public void setPosX(int x){posX = x;}
    public void setPosY(int y){posY = y;}

    public double calcDistance(Treasure t){
        double difX = posX - t.getPosX();
        double difY = posY - t.getPosY();
        double distance = Math.sqrt(Math.pow(difX,2)+Math.pow(difY,2));
        return distance;
    }

    public boolean findTreasure(Treasure t){
        boolean isFind=true;
        if(this.posX != t.getPosX() && this.posY != t.getPosY()){
            isFind = false;
            System.out.println("Wrong answer!");
            System.out.printf("The distance between you and treasure is %.2f\n",calcDistance(t));
        }else{
            System.out.println("Congratulation, you had found the treasure");
            addScore(t);
            isFind = true;
        }
        return isFind;
    }

    public void addScore(Treasure t){
        this.score += t.getPoint();
    }

    public boolean comparePlayer(Player2 p){
        return this.score > p.getScore();
    }
}

class Game{
    private static Player2 scoreboard[];
    private static int count;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Please enter your name:");
        String name=sc.nextLine();

        Player2 p = new Player2(name);
        boolean isContinue = true;
        String repeat = "y";

        do {
            Treasure t = new Treasure();

            //stop when find the treasure
            do {
                int posX = getPosInput("Enter position X:");
                int posY = getPosInput("Enter position Y:");

                p.setPosX(posX);
                p.setPosY(posY);

                isContinue = p.findTreasure(t);
            } while (isContinue);

            System.out.println("Do you want to continue?[Y/N]");
            repeat = sc.next();
        }while(repeat.equalsIgnoreCase("y"));

        //get score
        int score = p.getScore();
        System.out.println("Your score is "+score);

        int index=0;
        for(int i=0;i<count;++i){
            if(p.comparePlayer(scoreboard[i])){
                index = i;
            }
        }
        for(int i=count-1;i>index;++i){
            if(i==scoreboard.length-1){
                continue;
            }

            scoreboard[i+1] = scoreboard[i];
        }

        printScoreBoard();
    }

    public static int getPosInput(String prompt){
        Scanner sc = new Scanner(System.in);
        System.out.print(prompt);
        int input = sc.nextInt();

        //validation
        //(0-100)
        while(input<0 || input>100) {
            System.out.println("Invalid input, the position should between 0 - 100");
            System.out.print(prompt);
            input = sc.nextInt();
        }

        return input;
    }

    public static void printScoreBoard(){
        System.out.printf("%-20s%-10s\n","Name","Mark");
        System.out.println("--------------------------------");
        for(int i=0;i<count;i++){
            System.out.printf("%-20s%-10d\n",scoreboard[i].getName(),scoreboard[i].getScore());
        }
    }
}
