import javax.swing.JOptionPane;
import java.util.Scanner;

public class Week9_Lab2
{
    public static void main (String[] args)
    {
        String[] artist = {"Arcade Fire", "Metallica", "Snow Patrol",
                "Leonard Cohen", "Black Eyed Peas"};
        String[] title  = {"Neon Bible", "And Justice for All", "Eyes Open",
                "Cohen Live", "Elephunk [Bonus Track]"};
        int[] cost  = {949, 999, 1099, 699, 699};

        //METHODS CALLS - MAIN METHOD
        printCD(artist, title, cost);
        //  prints CD details in a table

        printCDLessThan999(artist, title, cost);

        printArtistsCD(artist, title, cost);
        //  inputs artist’s name then prints out all that artist’s CD info.
    }

    // YOU NEED TO COMPLETE THE FOLLOWING METHODS
    // This method printCDs(String[] singers, String[] songs, int[] price)
    // prints out a heading for the CD info
    // then prints each CDs details on a separate line
    // then prints a blank line.
    public static void printCDs(String[] singers,String[] songs,int[] price){
        int length = singers.length;
        for(int i=0;i<length;i++){
            System.out.printf("Heading:%s\nArtist:%s\nPrice:%d\n\n",songs[i],singers[i],price[i]);
        }
    }

    public static void printCD(String[] singers,String[] songs,int[] price){
        System.out.printf("%-20s%-30s%-10s\n","Artist","Title","Price($)");
        int length = singers.length;
        for(int i=0;i<length;i++){
            System.out.printf("%-20s%-30s%-10s\n",singers[i],songs[i],price[i]);
        }
    }

    // This method printArtistsCDs
    // inputs an artist’s name
    // then checks each CD in turn to see if the input artist matches any of the CDs
    // using (artist.equals(singers[i]))
    // and if it does it outputs the CD details on one line.
    public static void printArtistsCDs(String[] singers,String[] songs,int[] price){
        Scanner sc = new Scanner(System.in);
        String artist="";

        System.out.print("Please enter artist:");
        artist = sc.nextLine();

        int length = songs.length;
        for(int i=0;i<length;i++){
            if(artist.equals(singers[i])){
                System.out.printf("Title:%s\nArtist:%s\nPrice:%d\n\n",songs[i],singers[i],price[i]);
            }
        }
    }

    public static void printArtistsCD(String[] singers,String[] songs,int[] price){
        String artist= JOptionPane.showInputDialog("Enter artist name: ");
        int pos=-1;

        for(int i=0;i<singers.length;i++){
            if(artist.equalsIgnoreCase(singers[i])){
                pos = i;
                break;
            }
        }
        if(pos!=-1){
            System.out.printf("\n%-20s%-30s%-10s\n",singers[pos],songs[pos],price[pos]);
        }else{
            System.out.println("\nArtist "+artist+" not found!\n");
        }
    }

    // This method printCDsLessThan999
    // checks the cost of each CD
    // and if it is less than 999 it outputs the CD’s info.
    public static void printCDsLessThan999(String[] singers,String[] songs,int[] price){
        int length = price.length;
        for(int i=0;i<length;i++){
            if(price[i]<999){
                System.out.printf("Heading:%s\nArtist:%s\nPrice:%d\n\n",songs[i],singers[i],price[i]);
            }
        }
        System.out.println();
    }

    public static void printCDLessThan999(String[] singers,String[] songs,int[] price){
        System.out.println("\nCD price less than 999\n");
        System.out.println("---------------------------------------");
        System.out.printf("%-20s%-30s%-10s\n","Artist","Title","Price($)");
        int length = singers.length;
        for(int i=0;i<length;i++){
            if(price[i]<999){
                System.out.printf("%-20s%-30s%-10s\n",singers[i],songs[i],price[i]);
            }
        }
    }
}

