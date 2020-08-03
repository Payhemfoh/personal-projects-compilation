import java.io.*;

public class Week12_Lab5 {
    public static void main(String[] args){
        File save = new File("./folder/file.txt");
        //path is used to create the directory
        File path = new File("./folder");
        try {
            if(!save.exists()) {
                if (!path.exists()) {
                    boolean createDir= path.mkdir();
                    if(createDir)
                        System.out.println("Success to create the directory");
                    else
                        throw new IOException("Failed to create the directory");
                }
                save.createNewFile();
                System.out.println("Success to create the file");
            }

            FileWriter fw = new FileWriter(save);
            PrintWriter pw = new PrintWriter(fw);

            pw.println("Hello");
            System.out.println("Success!");

            pw.close();
            fw.close();
        }catch(IOException e){
            System.out.println("Failed!"+e.getMessage());
            System.exit(-1);
        }
    }
}
