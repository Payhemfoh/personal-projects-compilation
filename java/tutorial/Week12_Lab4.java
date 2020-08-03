import java.io.*;
import java.util.Scanner;
import javax.swing.JOptionPane;

public class Week12_Lab4 {
    public static void main(String[] args) {
        File file = null;
        FileReader fr = null;

        try {
            String fileName = JOptionPane.showInputDialog("Enter File Name");

            file = new File(fileName);
            fr = new FileReader(file);
            Scanner sc = new Scanner(fr);
            int line = 0;

            while (line < 10 && sc.hasNext()) {
                System.out.println(sc.nextLine());
                ++line;
            }

            if (line < 10)
                System.out.println("All the content in the file had been printed!");

            sc.close();
            fr.close();
        }catch(FileNotFoundException e){
            System.out.println("Failed to open the File! The program will be closed!");
            System.exit(-1);
        }catch(NullPointerException e){
            System.out.println("The program will be closed!");
            System.exit(-1);
        }catch(Exception e){
            System.out.println("Unexpected error occured!");
            System.exit(-1);
        }
    }
}

class ComplicatedVer{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        File file = null;
        FileReader fr = null;
        Scanner fs = null;
        String fileName = "";
        boolean valid=false;
        do {
            try {
                System.out.print("Enter a file name:");
                fileName = sc.nextLine();
                if(fileName.trim().equals(""))
                    throw new NullPointerException();
                valid = true;
            } catch (NullPointerException e) {
                System.out.println("Invalid input! Please try again!");
            }
        }while(!valid);

        try {
            file = new File(fileName);
            fr = new FileReader(file);
            fs = new Scanner(fr);
            int line=0;

            //display first 10 line
            while(line<10 && fs.hasNextLine()){
                System.out.println(fs.nextLine());
                ++line;
            }

            if(line<9){
                System.out.println("\nAll file content fully displayed!");
            }

            fs.close();
            fr.close();
        }catch(FileNotFoundException e){
            try {
                System.out.println("Unable to open the file!");
                boolean result = file.createNewFile();
                if(!result)
                    throw new IOException();

                System.out.println("The new file is created");
                System.exit(-1);
            } catch(Exception ex){
                System.out.println("Failed to create the new file!");
                System.exit(-1);
            }
        }catch(Exception e){
            System.out.println("Error occur when process is running! Please try again!");
            System.exit(-1);
        }
    }
}
