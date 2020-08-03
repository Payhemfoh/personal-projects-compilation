import java.io.*;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class FileManagementModule {

    public static ArrayList<ITLab> readLab(ArrayList<PC> pcList){
        ArrayList<ITLab> list = null;
        try {
            FileReader fr = new FileReader("datafile/Lab.dat");
            Scanner sc = new Scanner(fr);
            int size = 0;
            System.out.println("data file detected, start to read data...\n");
            //read the initial size of the lab (first line of file)
            if (sc.hasNextLine()) {
                size = Integer.parseInt(sc.nextLine().trim());
            }
            //assign the list to new object by initialize the size
            list = new ArrayList<ITLab>(size + 10);

            while (sc.hasNextLine()) {
                String input = sc.nextLine().trim();
                String[] part = input.split(",");

                if(part.length!=2)
                    throw new InputMismatchException();

                ITLab temp = new ITLab(part[0]);

                while(sc.hasNextLine()&&!(input.equals(""))){
                    input = sc.nextLine().trim();

                    if(input.equals("")) {
                        break;
                    }
                    else{
                        String[] block = input.split(",");
                        if(block.length!=2)
                            throw new InputMismatchException();

                        PC computerTemp = new PC(block[0],block[1]);

                        for(PC ptr : pcList){
                            if(computerTemp.equals(ptr))
                                temp.addPC(ptr);
                        }
                    }
                }
                list.add(temp);
            }

            sc.close();
            fr.close();
        }catch(ArrayIndexOutOfBoundsException e) {
            System.out.println("Oops! An error occur when reading data from file!");
            System.exit(-1);
        }catch(FileNotFoundException e) {
            try {
                //check if file and directory is present
                File fileName = new File("datafile/Lab.dat");
                File path = new File("datafile/");
                //if directory is not present
                if (!(path.exists() && path.isDirectory())) {
                    System.out.println("Failed to found the directory :\"datafile\"!\nA new directory will be created!");
                    //create the directory
                    boolean createDir = path.mkdir();
                    if (createDir) {
                        System.out.println("The directory \"datafile\" had been created.\n");
                    } else {
                        throw new FileNotFoundException();
                    }
                }

                //check if file exists
                if (!fileName.exists()) {
                    System.out.println("Failed to found the file :\"Lab.dat\"!\nA new file will be created!");
                    boolean result = fileName.createNewFile();
                    if (result) {
                        System.out.println("The File is created Successfully!\n");
                    } else {
                        throw new FileNotFoundException();
                    }
                }

                list = new ArrayList<ITLab>();
            }catch(IOException ex){
                System.out.println("Oops! An error had occur when try to create the file!");
                System.exit(-1);
            }catch(Exception ex){
                System.out.println("Oops! An unexpected error occur when program is running!"+e.getMessage());
                System.exit(-1);
            }
        }catch(Exception e){
            System.out.println("Oops! An unexpected error occur when program is running!"+e.getMessage());
            System.exit(-1);
        }
        return list;
    }


    public static ArrayList<PC> readPC(ArrayList<Software> softwareList){
        ArrayList<PC> list = null;
        try {
            FileReader fr = new FileReader("datafile/PC.dat");
            Scanner sc = new Scanner(fr);
            int size = 0;

            System.out.println("data file detected, start to read data...\n");
            //read the initial size of the pc (first line of file)
            if (sc.hasNextLine()) {
                size = Integer.parseInt(sc.nextLine().trim());
            }

            //assign the list to new object by initialize the size
            list = new ArrayList<PC>(size + 10);

            while (sc.hasNextLine()) {
                String input = sc.nextLine().trim();
                String[] part = input.split(",");

                if(part.length!=6)
                    throw new InputMismatchException();

                PC temp = new PC(part[0],new IPv4(part[1]),part[2],Integer.parseInt(part[3]),Double.parseDouble(part[4]),part[5]);

                while(!input.equals("")) {
                    input = sc.nextLine().trim();
                    if(input.equals(""))
                        break;
                    else {
                        String[] block = input.split(",");

                        if (block.length != 2)
                            throw new InputMismatchException();

                        Software softwareTemp = new Software(block[0], block[1]);
                        for (Software s : softwareList) {
                            if (softwareTemp.equals(s)) {
                                temp.addSoftware(s);
                            }
                        }
                    }
                }
                list.add(temp);
            }

            sc.close();
            fr.close();
        }catch(ArrayIndexOutOfBoundsException e) {
            System.out.println("Oops! An error occur when reading data from file!");
            System.exit(-1);
        }catch(FileNotFoundException e) {
            try {
                //check if file and directory is present
                File fileName = new File("datafile/PC.dat");
                File path = new File("datafile/");
                //if directory is not present
                if (!(path.exists() && path.isDirectory())) {
                    System.out.println("Failed to found the directory :\"datafile\"!\nA new directory will be created!");
                    //create the directory
                    boolean createDir = path.mkdir();
                    if (createDir) {
                        System.out.println("The directory \"datafile\" had been created.\n");
                    } else {
                        throw new FileNotFoundException();
                    }
                }

                //check if file exists
                if (!fileName.exists()) {
                    System.out.println("Failed to found the file :\"PC.dat\"!\nA new file will be created!");
                    boolean result = fileName.createNewFile();
                    if (result) {
                        System.out.println("The File is created Successfully!\n");
                    } else {
                        throw new FileNotFoundException();
                    }
                }

                list = new ArrayList<PC>();
            }catch(IOException ex){
                System.out.println("Oops! An error had occur when try to create the file!");
                System.exit(-1);
            }catch(Exception ex){
                System.out.println("Oops! An unexpected error occur when program is running!"+e.getMessage());
                System.exit(-1);
            }
        }catch(Exception e){
            System.out.println("Oops! An unexpected error occur when program is running!"+e.getMessage());
            System.exit(-1);
        }

        return list;
    }


    public static ArrayList<Software> readSoftware(){
        ArrayList<Software> list = null;
        try {
            FileReader fr = new FileReader("datafile/Software.dat");
            Scanner sc = new Scanner(fr);
            int size = 0;

            System.out.println("data file detected, start to read data...\n");
            //read the initial size of the software (first line of file)
            if (sc.hasNextLine()) {
                size = Integer.parseInt(sc.nextLine().trim());
            }

            //assign the list to new object by initialize the size
            list = new ArrayList<Software>(size + 10);

            //read all data from file
            while (sc.hasNextLine()) {
                String input = sc.nextLine().trim();
                String[] part = input.split(",");

                if(part.length!=4)
                    throw new InputMismatchException();

                Software temp = new Software(part[0],part[1],Double.parseDouble(part[2]),part[3]);
                list.add(temp);
            }

            sc.close();
            fr.close();
        }catch(InputMismatchException | NumberFormatException | ArrayIndexOutOfBoundsException e){
            System.out.println("Oops! An error occur when reading data from file!");
            System.exit(-1);
        }catch(FileNotFoundException e) {
            try {
                //check if file and directory is present
                File fileName = new File("datafile/Software.dat");
                File path = new File("datafile/");
                //if directory is not present
                if (!(path.exists() && path.isDirectory())) {
                    System.out.println("Failed to found the directory :\"datafile\"!\nA new directory will be created!");
                    //create the directory
                    boolean createDir = path.mkdir();
                    if (createDir) {
                        System.out.println("The directory \"datafile\" had been created.\n");
                    } else {
                        throw new FileNotFoundException();
                    }
                }

                //check if file exists
                if (!fileName.exists()) {
                    System.out.println("Failed to found the file :\"Software.dat\"!\nA new file will be created!");
                    boolean result = fileName.createNewFile();
                    if (result) {
                        System.out.println("The File is created Successfully!\n");
                    } else {
                        throw new FileNotFoundException();
                    }
                }

                list = new ArrayList<Software>();
            }catch(IOException ex){
                System.out.println("Oops! An error had occur when try to create the file!");
                System.exit(-1);
            }catch(Exception ex){
                System.out.println("Oops! An unexpected error occur when program is running!"+e.getMessage());
                System.exit(-1);
            }
        }catch(Exception e){
            System.out.println("Oops! An unexpected error occur when program is running!"+e.getMessage());
            System.exit(-1);
        }

        return list;
    }


    public static void writeLab(ArrayList<ITLab> list){
        try {
            FileWriter fw = new FileWriter("datafile/Lab.dat");
            PrintWriter pw = new PrintWriter(fw);
            int size = list.size();

            pw.println(size);

            for (ITLab itLab : list) {
                pw.println(itLab);
                for(int i=0;i< itLab.getNumComputer();++i){
                    pw.printf("%s,%s\n",itLab.getPC(i).getName(),itLab.getPC(i).getIp());
                }
                pw.println(" ");
            }

            System.out.println("All data had been saved into data file\n");
            pw.close();
            fw.close();
        }catch(ArrayIndexOutOfBoundsException e) {
            System.out.println("Oops! An error occur when writing data into file!");
            System.exit(-1);
        }catch(IOException e) {
            System.out.println("Failed to open file to write data!");
            System.exit(-1);
        }catch(Exception e){
            System.out.println("Oops! An unexpected error occur when program is running!"+e.getMessage());
            System.exit(-1);
        }
    }


    public static void writePC(ArrayList<PC> list){
        try {
            FileWriter fw = new FileWriter("datafile/PC.dat");
            PrintWriter pw = new PrintWriter(fw);
            int size = list.size();

            pw.println(size);

            for (PC pc : list) {
                pw.println(pc);
                for(int i=0;i<pc.getNumSoftware();++i){
                    pw.printf("%s,%s\n",pc.getSoftware(i).getName(),pc.getSoftware(i).getType());
                }
                pw.println(" ");
            }

            System.out.println("All data had been saved into data file\n");
            pw.close();
            fw.close();
        }catch(ArrayIndexOutOfBoundsException e) {
            System.out.println("Oops! An error occur when writing data into file!");
            System.exit(-1);
        }catch(IOException e) {
            System.out.println("Failed to open file to write data!");
            System.exit(-1);
        }catch(Exception e){
            System.out.println("Oops! An unexpected error occur when program is running!"+e.getMessage());
            System.exit(-1);
        }
    }


    public static void writeSoftware(ArrayList<Software> list){
        try {
            FileWriter fw = new FileWriter("datafile/Software.dat");
            PrintWriter pw = new PrintWriter(fw);
            int size = list.size();

            pw.println(size);

            for (Software software : list) {
                pw.println(software);
            }

            System.out.println("All data had been saved into data file\n");
            pw.close();
            fw.close();
        }catch(ArrayIndexOutOfBoundsException e) {
            System.out.println("Oops! An error occur when writing data into file!");
            System.exit(-1);
        }catch(IOException e) {
            System.out.println("Failed to open file to write data!");
            System.exit(-1);
        }catch(Exception e){
            System.out.println("Oops! An unexpected error occur when program is running!"+e.getMessage());
            System.exit(-1);
        }
    }
}
