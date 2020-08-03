/*
 * This program is a class of Card
 */

/**
 * Card class
 * @author Payhemfoh
 */
/*
*/
import java.util.Random;
import java.util.Scanner;

class Card {
    //fields
    private String rank;
    private String suite;
    
    /*
    -----------constructor---------------
     */

    /**
     * default constructor of Card
     * set rank to 2 and suite to Diamond as default
     */
    public Card(){
        rank = "2";
        suite = "Diamonds";
    }//end constructor

    /**
     * overloaded constructor of Card
     * @param r the rank of the card
     * @param suite the suite of the card
     */
    public Card(int r,String suite){
        String rank = convertRank(r);
        this.suite = suite.toUpperCase();
        this.rank = rank.toUpperCase();
    }//end constructor

    /**
     * Copy constructor of card to create a same card object from current object
     * @param c Card object
     */
    public Card(Card c){
        this.suite=c.getSuite();
        this.rank=c.getRank();
    }//end constructor
    /*
    --------------getter----------------------
     */

    /**
     * Getter which return the suite of object
     * @return suite the suite of object
     */
    public String getSuite(){ return suite; }

    /**
     * Getter which return the rank of object
     * @return rank the rank of object
     */
    public String getRank(){ return rank; }
    
    /*
    ------------------setter------------------------
     */

    /**
     * Setter which set the suite of object
     * @param suite the suite to set to object in uppercase
     */
    public void setSuite(String suite){this.suite = suite.toUpperCase();}

    /**
     * Setter which set the rank of object
     * @param r the rank to set to object
     */
    public void setRank(int r){
        //convert the integer input to string and replace the object's rank
        this.rank = convertRank(r);
    }
    
    /*
    ---------------toString method------------------------
     */

    /**
     * toString() method to prevent error when print out the object directly
     * @return text String which contain rank and suite of object
     */
    public String toString(){
        return rank + " of " + suite;
    }//end method
    
    /**
     * This method convert the integer input of rank into String form
     * @param r integer input of rank
     * @return result - String form of the rank in uppercase
     */
    private static String convertRank(int r){
        String result="";
        switch(r){
            case 1:
                result="Ace";
                break;
            case 11:
                result="Jack";
                break;
            case 12:
                result="Queen";
                break;
            case 13:
                result="King";
                break;
            default:
                result = Integer.toString(r);
        }

        return result.toUpperCase();
    }//end method

    /**
     * This method create and return a new random Card
     * @return sample - The new Card with rank and suite generated with random number
     */
    public static Card issueCard(){
        //use random number to generate the rank and suite
        Random rd = new Random();
        String suite="";
        int suiteNum = rd.nextInt(4);
        int rank = rd.nextInt(13)+1;
        switch(suiteNum){
            case 0:
                suite = "SPADES";
                break;
            case 1:
                suite = "DIAMONDS";
                break;
            case 2:
                suite = "CLUBS";
                break;
            case 3:
                suite = "HEARTS";
                break;
            default:
                System.out.println("Oops!Error occur when getting suite String of card!");
                System.exit(-1);
        }
        return new Card(rank,suite);
    }//end method

    /**
     * check either the suite input is valid
     * @param suite the suite input from user
     * @return result boolean which show result of validation
     */
    private static boolean is_valid_suite(String suite){
        boolean result=false;
        if(suite.equalsIgnoreCase("Diamonds"))
            result=true;
        else if(suite.equalsIgnoreCase("spades"))
            result=true;
        else if(suite.equalsIgnoreCase("clubs"))
            result=true;
        else if(suite.equalsIgnoreCase("hearts"))
            result=true;
        return result;
    }

    /**
     * check either the rank input is valid
     * @param rank the rank input by the user
     * @return result the boolean result of the validation
     */
    private static boolean is_valid_rank(int rank){
        boolean result=false;
        if(rank>=1&&rank<=13)
            result = true;
        return result;
    }

    /**
     * method to get String input from user
     * @param text prompt text to show
     * @return input String entered by user
     */
    private static String getString(String text){
        //use scanner class to get string input from user
        Scanner sc = new Scanner(System.in);
        System.out.print(text);
        String input=sc.next();
        return input;
    }//end method

    /**
     * method to get integer input from user
     * @param text prompt text to show
     * @return input integer entered by user
     */
    private static int getInteger(String text){
        //use scanner class to get integer input from user
        Scanner sc = new Scanner(System.in);
        System.out.print(text);
        int input=sc.nextInt();
        return input;
    }//end method

    /**
     * get suite input and validate the input
     * @return suite the suite input for the object from user
     */
    public static String getSuiteInput(){
        String suite=getString("Enter suite:");
        while(!is_valid_suite(suite)){
            System.out.println("Invalid input, the suite should be in [Diamonds,Spades,Clubs,Hearts].");
            suite=getString("Enter suite:");
        }
        return suite;
    }

    /**
     * get rank input and validate the input
     * @return rank the rank input for the object from user
     */
    public static int getRankInput(){
        int rank=getInteger("Enter rank:");
        while(!is_valid_rank(rank)){
            System.out.println("Invalid input, the rank should between 1 - 13.");
            rank=getInteger("Enter rank:");
        }
        return rank;
    }
}//end class

class CardDriver{
    public static void main(String[] args){
        //initialize the variables
        String suite="";
        int rank=0;

        //create a card using default constructor
        System.out.println("Create card with default constructor:");
        Card c1 = new Card();
        System.out.printf("c1:suite=%s,rank=%s\n\n",c1.getSuite(),c1.getRank());

        //create a card using overloaded constructor
        System.out.println("Create card with overloaded constructor:");
        suite=Card.getSuiteInput();
        rank=Card.getRankInput();
        Card c2 = new Card(rank,suite);
        System.out.printf("c2:suite=%s,rank=%s\n\n",c2.getSuite(),c2.getRank());

        //create a card using copy constructor
        System.out.println("Create card with copy constructor:");
        Card c3 = new Card(c2);
        System.out.printf("c3:suite=%s,rank=%s\n\n",c3.getSuite(),c3.getRank());

        //change the suite and rank of card created with default constructor
        System.out.println("Change card created with default constructor:");
        suite=Card.getSuiteInput();
        rank=Card.getRankInput();
        c1.setSuite(suite);
        c1.setRank(rank);
        System.out.println("c1:"+c1+"\n\n");

        //issue card, calculate and print out the number of card with Diamonds suite
        testIssueCard();
    }//end main

    /**
     * This method is used to test the issue card method.
     */
    private static void testIssueCard(){
        int diamondCard=0;
        //10 random card is issued
        System.out.println("Random Issuing Cards:");
        for(int i=0;i<10;i++){
            //get the card with issueCard() method
            Card randomIssuedCard=Card.issueCard();
            //print out the card
            System.out.printf("Random Issued Card #%d:%s\n",i+1,randomIssuedCard);
            //if card is diamonds suite then add to counter
            if(randomIssuedCard.getSuite().equalsIgnoreCase("Diamonds"))
                diamondCard++;
        }
        //print out the number of card with diamond suite
        System.out.println("The number of random issued card with diamond suite are "+diamondCard);
    }
}//end class