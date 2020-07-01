/*
    This program read a sentence and a character
    then calculate the occurrence of the character in the text
*/
import java.util.Scanner;

public class Week6_Lab4 {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Please enter a sentence:");
        String text = sc.nextLine();
        System.out.print("Please enter a character:");
        char target=sc.next().charAt(0);
        searchOccur(text,target);
    }
    
    /**
     * The program calculate and print out the occurrence of a character in sentence.
     * @param str a sentence
     * @param target a character
     */
    public static void searchOccur(String str,char target)
    {
        int count = 0;
        
        for(int i=0;i<str.length();i++){
            if(str.charAt(i)==target){
                count++;
            }
        }
        
        if(count==0){
            System.out.println("The character is not found in the text.");
        }else{
            System.out.printf("The character %s appear %d times in the sentence\n", target,count);
        }
        
    }
    
    /**
     * This method search and return either a character is in the sentence.
     * @param str the sentence
     * @param target the character to be found in the sentence
     * @return result the search result either the character is found in sentence
     */
    public static boolean isFound(String str,char target)
    {
        boolean result = false;
        for(int i=0;i<str.length();i++){
            if(str.charAt(i)==target){
                result = true;
                break;
            }
        }
        return result;
    }
    
    /**
     * This method search and print the first occurrence of the character in the sentence
     * @param str the sentence
     * @param target the character to be found in the sentence
     */
    public static void findCharacter(String str,char target)
    {
        boolean found = false;
        int index=0;
        for(int i=0;i<str.length();i++)
        {
            if(str.charAt(i)==target){
                found=true;
                index=i;
                break;
            }
        }
        if(found){
            System.out.printf("The character %s is found at index %d of sentence\n",target,index );
        }else{
            System.out.printf("The character %s is not found in the sentence \n",target);
        }
    }
    
}
