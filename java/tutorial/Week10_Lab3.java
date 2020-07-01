import java.io.*;
import java.util.Scanner;

public class Week10_Lab3 {
    private static Week10_Lab2 list[];
    private static int CDSIZE = 5;

    public static void main(String args[]) throws IOException{
        list = new Week10_Lab2[CDSIZE];
        readCD();

        printCD();

        exportCDList();
    }

    public static void readCD() throws IOException{
        FileReader fr = new FileReader("cd.txt");
        Scanner sc = new Scanner(fr);
        String artist="",title="";
        int cost=0;

        for(int i=0;i<CDSIZE;i++){
            artist = sc.nextLine();
            title = sc.nextLine();
            cost = Integer.parseInt(sc.nextLine());

            Week10_Lab2 cd = new Week10_Lab2(artist,title,cost);
            list[i] = cd;
        }

    }

    public static void printCD(){
        System.out.printf("%-30s%-30s%-7s\n","Artist","Title","Cost($)");
        System.out.println("--------------------------------------------------------------");

        for(int i=0;i<CDSIZE;i++){
            System.out.printf("%-30s%-30s%-7d\n",list[i].getArtist(),list[i].getTitle(),list[i].getCost());
        }
    }

    public static void exportCDList() throws IOException{
        FileWriter fw = new FileWriter("cd.html");
        PrintWriter pw = new PrintWriter(fw);

        pw.println("<!DOCTYPE html>\n<html lang='en'>\n<head>\n<title>CD List</title>\n<meta charset='utf-8'>\n</head>");
        pw.println("<body><table border='1'>");

        pw.println("<tr><th>Artist</th><th>Title</th><th>Cost($)</th></tr>");
        for(int i=0;i<CDSIZE;i++){
            pw.printf("<tr><td>%s</td><td>%s</td><td>%d</td></tr>",list[i].getArtist(),list[i].getTitle(),list[i].getCost());
        }

        pw.println("</table></body>");

        System.out.println("The cd list had been export into the html file");
        pw.close();
    }
}
