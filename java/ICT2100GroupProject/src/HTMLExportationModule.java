import java.io.*;
import java.util.ArrayList;

public class HTMLExportationModule {
    /**
     * This method is the driver method of this module which will export all data and saved in HTML format
     * @param labList the Array List of the ITLab object
     * @param pcList the Array List of the PC object
     * @param softwareList the Array List of the Software object
     */
    public static void export(ArrayList<ITLab> labList,ArrayList<PC> pcList,ArrayList<Software> softwareList){
        try {
            exportTable(labList, pcList, softwareList);
            exportSoftware(softwareList);
            exportPC(pcList);
            exportLab(labList);
            System.out.println("All the output files already saved into the output directory.\n");
        }catch(Exception e){
            System.out.println("Oops! Failed to export the HTML file."+e.getMessage());
        }//end catch
    }//end method

    /**
     * This method will export all the general data and save into table form in HTML format
     * @param labList the Array List of the ITLab object
     * @param pcList the Array List of the PC object
     * @param softwareList the Array List of the Software object
     */
    private static void exportTable(ArrayList<ITLab> labList,ArrayList<PC> pcList,ArrayList<Software> softwareList){
        File save = new File("./output/GeneralTable.html");
        //path is used to create the directory
        File path = new File("./output");
        try {
            //check if the file is exists
            if(!save.exists()) {
                if (!path.exists()) {
                    //create the directory if the directory is not exist
                    boolean createDir= path.mkdir();
                    if(createDir)
                        System.out.println("Success to create the directory");
                    else
                        throw new IOException("Failed to create the directory");
                }//end if directory is not exist

                //create the file after the directory exists
                save.createNewFile();
                System.out.println("Success to create the file");
            }//end if file is not exist

            FileWriter fw = new FileWriter(save);
            PrintWriter pw = new PrintWriter(fw);

            //HTML header
            pw.println("<!DOCTYPE html><html lang=\"en\"><head><title>General Table</title><meta charset=\"utf-8\"><body>");

            //Table for IT Lab object
            pw.println("<h1> ITLab </h1>");
            pw.println("<table border=\"1\" spacing=\"4\">");
            pw.println("<tr><th>Name</th><th>No.Computer</th></tr>");

            //loop through all object and display in table format
            for(ITLab lab : labList){
                pw.println("<tr>");
                pw.printf("<td><a href=\"./Lab.html#%s\">%s</a></td>",lab.getName().replace(' ','_'),lab.getName());
                pw.println("<td>" + lab.getNumComputer() +  "</td>");
                pw.println("</tr>");
            }//end for loop

            pw.println("</table>");
            pw.println("<br><br>");

            //Table for PC object
            pw.println("<h1> PC </h1>");
            pw.println("<table border=\"1\" spacing=\"4\">");
            pw.println("<tr>");
            pw.println("<th>Name</th><th>IP</th><th>ComputerType</th><th>YearManufacture</th><th>RamRequirement</th><th>LabName</th>");
            pw.println("</tr>");

            //loop through all object and display in table format
            for(PC pc : pcList){
                pw.println("<tr>");
                pw.printf("<td><a href=\"./PC.html#%s\">%s</a></td>",pc.getName().replace(' ','_'),pc.getName());
                pw.println("<td>" + pc.getIp() +  "</td>");
                pw.println("<td>" + pc.getComputerType() + "</td>");
                pw.println("<td>" + pc.getYearManufacture() + "</td>");
                pw.println("<td>" + pc.getRamRequirement() + "</td>");
                pw.println("<td>" + pc.getLabName() + "</td>");
                pw.println("</tr>");
            }//end for loop

            pw.println("</table>");
            pw.println("<br><br>");

            //Table for Software object
            pw.println("<h1> Software </h1>");
            pw.println("<table border=\"1\" spacing=\"4\">");
            pw.println("<tr>");
            pw.println("<th>Name</th><th>Type</th><th>RamRequirement</th><th>ExpireDate</th>");
            pw.println("</tr>");

            //loop through all object and display in table format
            for(Software software : softwareList){
                pw.println("<tr>");
                pw.printf("<td><a href=\"./Software.html#%s\">%s</a></td>",software.getName().replace(' ','_'),software.getName());
                pw.println("<td>" + software.getType() +  "</td>");
                pw.println("<td>" + software.getRamRequirement() + "</td>");
                pw.println("<td>" + software.getExpireDate() +"</td>");
                pw.println("</tr>");
            }//end for loop

            pw.println("</table>");
            pw.println("</body></html>");

            //display the success message and close the pw and fw
            System.out.println("GeneralTable.html exported successfully.\n");
            pw.close();
            fw.close();

        } catch(IOException e){
            System.out.println("Failed to open file to write data. Please try again later.");
        } catch(Exception e){
            System.out.println("An unexpected error had occur during the process."+e.getMessage());
        }//end catch
    }//end method

    /**
     * This method export the IT Lab objects in the list into HTML file which contain the details of the IT Lab objects
     * The detail included Name, No.Computer and the list of PC objects in the computer list of the IT object
     * At the beginning, the path to the file and directory is check and if not found,
     * the new directory and the file will be created.
     * @param list The list of the ITLab objects to be export into the HTML file.
     */
    private static void exportLab(ArrayList <ITLab> list){
        File save = new File("./output/Lab.html");
        //path is used to create the directory
        File path = new File("./output");
        try {
            //check if the file is exists
            if(!save.exists()) {
                if (!path.exists()) {
                    //create the directory if the directory is not exist
                    boolean createDir= path.mkdir();
                    if(createDir)
                        System.out.println("Success to create the directory");
                    else
                        throw new IOException("Failed to create the directory");
                }//end if directory is not exist

                //create the file after the directory exists
                save.createNewFile();
                System.out.println("Success to create the file");
            }//end if file is not exist
            FileWriter fw = new FileWriter(save);
            PrintWriter pw = new PrintWriter(fw);

            //start writing the HTML file
            pw.println("<!DOCTYPE html>");
            pw.println("<html lang-\"en\">");
            
            pw.println("<head>");
            pw.println("<title>IT Lab</title>");
            pw.println("<meta charset =\"utf-8\">");
            pw.println("</head>");
    
            pw.println("<body>");

            //loop through the list and output all detail
            for(ITLab List: list){
                //The a tag is used as a label for the link
                pw.printf("<a name=\"%s\">",List.getName().replace(' ','_'));
                pw.printf("Name:%s<br>",List.getName());
                pw.printf("No.Computer:%d<br>",List.getNumComputer());
                pw.println("<table border=\"1\" spacing=\"3\">");
                pw.println("<tr><th>Index</th><th>PC Name</th><th>IPv4(GB)</th></tr>");

                //The loop is used to loop through the computer list and output the PC information
                for(int i=0;i<List.getNumComputer();i++){
                    pw.println("<tr>");
                    pw.printf("<td>%d</td>",i+1);
                    pw.printf("<td><a href=\"PC.html#%s\">%s</a></td>",List.getPC(i).getName().replace(' ','_'),List.getPC(i).getName());
                    pw.printf("<td>%s(GB)</td>",List.getPC(i).getIp());
                    pw.print("<tr>");
                }//end pc for loop
                pw.println("</table></a>");
                pw.println("<br><br>");
            }//end lab for loop

            pw.println("</body>");
            pw.println("</html");

            //display the success message and close the pw and fw
            System.out.println("Lab.html exported successfully.\n");
            pw.close();
            fw.close();
        }catch(IOException e){
            System.out.println("Failed!"+e.getMessage());
            System.exit(-1);
        }catch(Exception e){
            System.out.println("Unexpected Error occur during the process."+e.getMessage());
            System.exit(-1);
        }
    }

    /**
     * This method export the PC objects in the list into HTML file which contain the details of the PC objects
     * The detail included Name, IP, Type, Year Manufacture, Ram Requirement, Lab Name
     * the list of Software objects in the software list of the PC object
     * At the beginning, the path to the file and directory is check and if not found,
     * the new directory and the file will be created.
     * @param list The list of the PC objects to be export into the HTML file.
     */
    private static void exportPC(ArrayList <PC> list){
        File save = new File("./output/PC.html");
        //path is used to create the directory
        File path = new File("./output");
        try {
            //check if the file is exists
            if(!save.exists()) {
                if (!path.exists()) {
                    //create the directory if the directory is not exist
                    boolean createDir= path.mkdir();
                    if(createDir)
                        System.out.println("Success to create the directory");
                    else
                        throw new IOException("Failed to create the directory");
                }//end if directory is not exist

                //create the file after the directory exists
                save.createNewFile();
                System.out.println("Success to create the file");
            }//end if file is not exist
            FileWriter fw = new FileWriter(save);
            PrintWriter pw = new PrintWriter(fw);

            //start writing HTML content
            pw.println("<DOCTYPE HTML>");
            pw.println("<html lang-\"en\">");
            
            pw.println("<head>");
            pw.println("<title>PC</title>");
            pw.println("<meta charset =\"utf-8\">");
            pw.println("</head>");
            
            pw.println("<body>");

            //loop through the list and output all detail
            for(PC pc: list){
                //The a tag is used as a label for the link
                pw.printf("<a name=\"%s\">",pc.getName().replace(' ','_'));
                pw.printf("Name:%s<br>",pc.getName());
                pw.printf("IPv4:%s<br>",pc.getIp());
                pw.printf("Computer type:%s<br>",pc.getComputerType());
                pw.printf("Year of manufacture:%d<br>",pc.getYearManufacture());
                pw.printf("Ram Requirement:%.2f<br>",pc.getRamRequirement());
                //ternary operator to display the lab name
                pw.printf("Lab Name:%s<br>",pc.getLabName().equals("--")?"This pc is not under any of the IT Lab":pc.getLabName());
                pw.println("<table border=\"1\" spacing=\"3\">");
                pw.println("<tr><th>Index</th><th>Software Name</th><th>Ram Requirement(GB)</th></tr>");

                //The loop is used to loop through the computer list and output the Software information
                for(int i=0;i<pc.getNumSoftware();i++){
                    pw.println("<tr>");
                    pw.printf("<td>%d</td>",i+1);
                    pw.printf("<td><a href=\"Software.html#%s\">%s</a></td>",pc.getSoftware(i).getName().replace(' ','_'),pc.getSoftware(i).getName());
                    pw.printf("<td>%.2f(GB)</td>",pc.getSoftware(i).getRamRequirement());
                    pw.print("<tr>");
                }//end software for loop

                pw.println("</table></a>");
                pw.println("<br><br>");
            }//end pc for loop

            pw.println("</body>");
            pw.println("</html");

            //display the success message and close the pw and fw
            System.out.println("PC.html exported successfully.\n");
            pw.close();
            fw.close();
        }catch(IOException e){
            System.out.println("Failed!"+e.getMessage());
            System.exit(-1);
        }catch(Exception e){
            System.out.println("Unexpected Error occur during the process."+e.getMessage());
            System.exit(-1);
        }//end catch block
    }//end method

    /**
     * This method export the Software objects in the list into HTML file which contain the details of the Software objects
     * The detail included Name, Type, Ram Requirement and ExpireDate
     * At the beginning, the path to the file and directory is check and if not found,
     * the new directory and the file will be created.
     * @param list The list of the Software objects to be export into the HTML file.
     */
    private static void exportSoftware(ArrayList <Software> list){
        File save = new File("./output/Software.html");
        //path is used to create the directory
        File path = new File("./output");
        try {
            //check if the file is exists
            if(!save.exists()) {
                if (!path.exists()) {
                    //create the directory if the directory is not exist
                    boolean createDir= path.mkdir();
                    if(createDir)
                        System.out.println("Success to create the directory");
                    else
                        throw new IOException("Failed to create the directory");
                }//end if directory is not exist

                //create the file after the directory exists
                save.createNewFile();
                System.out.println("Success to create the file");
            }//end if file is not exist

            FileWriter fw = new FileWriter(save);
            PrintWriter pw = new PrintWriter(fw);

            //start writing HTML content
            pw.println("<!DOCTYPE html>");
            pw.println("<html lang-\"en\">");
            pw.println("<head>");
            pw.println("<title>Software</title>");
            pw.println("<meta charset =\"utf-8\">");
            pw.println("</head>");
            
            pw.println("<body>");
            //loop through all object in the list
            for(Software software: list){
                //The a tag is used as a label for the link
                pw.printf("<a name=\"#%s\">",software.getName().replace(' ','_'));
                pw.printf("Name: %s<br>",software.getName());
                pw.printf("Type: %s<br>",software.getType());
                pw.printf("Ram Requirement:%.2f GB<br>",software.getRamRequirement());
                pw.printf("Expire Date: %s<br>",software.getExpireDate());
                pw.println("</a><br><br>");
            }//end for loop

            pw.println("</body>");
            pw.println("</html");

            //display the success message and close the pw and fw
            System.out.println("Software.html exported successfully.\n");
            pw.close();
            fw.close();
        }catch(IOException e){
            System.out.println("Failed!"+e.getMessage());
            System.exit(-1);
        }catch(Exception e){
            System.out.println("Unexpected Error occur during the process."+e.getMessage());
            System.exit(-1);
        }//end catch block
    }//end method
}//end class