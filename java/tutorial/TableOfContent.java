/*
This program get the book title, chapter description and number of page from user
and display the table of content to the user based on the input.
 */
import java.util.Scanner;

public class TableOfContent {

    public static void main(String args[]) {
        //declare the variables needed to get and store input
        Scanner sc = new Scanner(System.in);
        int chapter = 0, pageNo = 0, previousPageNo = 0;
        String title = "", descriptionList = "", pageNoList = "", input = "";

        //declare variable needed for printing
        int descriptionStart = 0, descriptionEnd = 0, pageNoStart = 0, pageNoEnd = 0, counter = 0;
        String descriptionSubstring = "", pageSubstring = "", formatedString = "";

        //get information from user
        //book title
        System.out.print("Enter Book Title : ");
        title = sc.nextLine();
        
        /*
            validate book title
            conditions: length <= 40 and the title should not be empty
        */
        if (title.length() > 40 || title.equals("")) {
            System.out.println("The title is too long or too short!!(max:40 character,min:1 character)");
            System.out.print("Enter Book Title : ");
            title = sc.nextLine();
        }
        
        //loop until user enter !Q
        do {
            //get chapter description input
            System.out.printf("Chapter #%d Description: ", chapter + 1);
            input = sc.nextLine();
            
            /*
                validate chapter description 
                condition: max-character-size: 40 char and title should not be empty
             */
            while (input.length() > 40 || input.equals("")) {
                System.out.println("The chapter description is too long or too short!!(max:40 character,min:1 character)");
                System.out.printf("Chapter #%d Description: ", chapter + 1);
                input = sc.nextLine();
            }

            //get page number input
            //if user enter !Q then skip the page number part
            if (!input.equalsIgnoreCase("!Q")) {
                System.out.print("Page Number: ");
                pageNo = sc.nextInt();

                //remove keyboard buffer
                sc.nextLine();
                /*
                    validate page number
                    condition: between 1 <= pageNo <= 500
                    condition: pageNo cannot smaller than last pageNo
                 */

                while (pageNo < 1 || pageNo > 500 || pageNo <= previousPageNo) {
                    System.out.println("The page number should be in range of 1 to 500 and page number should be larger than previous page number!!");
                    System.out.print("Page Number: ");
                    pageNo = sc.nextInt();
                    sc.nextLine();
                }

                //append the discription and page number into list
                descriptionList = descriptionList + input + ";";
                pageNoList = pageNoList + pageNo + ";";
                chapter++;

                //change current page number to previous page number for next loop
                previousPageNo = pageNo;
            }

        } while (!input.equalsIgnoreCase("!Q") || pageNo == 500);//end the input looping

        //start print the TOC
        System.out.println("Ready to print TOC...\n");

        /*
            print the title
            formating the title for center alignment (max-width : 50 char)
            to calculate the empty space: (50 - title length)
            the empty space should be divided evenly: (50 - title length) /2
            and the padding should include title length and spacing in left side(before the title): title length + (50-title length)/2
            the divided value should be integer as this is the padding for title
        */
        String titleFormat = String.format("%" + (title.length() + (50 - title.length()) / 2) + "s", title);
        System.out.println(titleFormat);

        //loop for printing content
        while (counter < chapter) {
            //set the end index for description and page number
            descriptionEnd = descriptionList.indexOf(";", descriptionStart);
            pageNoEnd = pageNoList.indexOf(";", pageNoStart);

            //get substring from indexes
            pageSubstring = pageNoList.substring(pageNoStart, pageNoEnd);
            descriptionSubstring = descriptionList.substring(descriptionStart, descriptionEnd);

            //format output
            //for the empty space in the page number, calculate the padding and replace the space padding into the dots
            formatedString = String.format("%s", descriptionSubstring)
                    + (String.format("%" + (50 - descriptionSubstring.length()) + "s", pageSubstring)).replaceAll(" ", ".");

            //print out line
            System.out.println(formatedString);

            //change the start index for description and page number
            descriptionStart = descriptionEnd + 1;
            pageNoStart = pageNoEnd + 1;
            counter++;
        }
        sc.close();
    }//end main
}//end class
