import java.util.ArrayList;
import java.util.Scanner;

public class MenuSystem {
    public static void main(String[] args){
        Menu menu = new Menu();
        menu.addMenuItem(new MenuItem(1,"Print Student Attendance"));
        menu.addMenuItem(new MenuItem(2,"Record Student Attendance"));
        menu.addMenuItem(new MenuItem(3,"Export Student Attendance"));
        menu.addMenuItem(new MenuItem(4,"End Program"));

        //create the listener object
        Menu.MenuListener listener = new Menu.MenuListener() {
            @Override
            public void selectOption(int option) {
                switch (option) {
                    case 1 -> System.out.println("Testing 1");
                    case 2 -> System.out.println("Testing 2");
                    case 3 -> System.out.println("Testing 3");
                    case 4, -1 -> {
                        System.out.println("Bye");
                        System.exit(-1);
                    }
                    default -> System.out.println("Invalid option!");
                }
            }
        };
        //set the listener to the menu
        menu.setMenuListener(listener);

        menu.startMenu();
    }
}

class MenuItem{
    private int no;
    private String description;

    public MenuItem(int n,String d){
        no = n;
        description = d;
    }

    //getter
    public int getNo(){return no;}
    public String getDescription(){return description;}

    //setter
    public void setNo(int n){no = n;}
    public void setDescription(String d){description = d;}

    public String toString(){
        return no+"->"+description;
    }//end method

}//end class

class Menu{
    private ArrayList<MenuItem> itemList;
    private Scanner sc;
    MenuListener myListener;    //act as reference from parent class

    //this interface is for communication
    public interface MenuListener{
        //abstract method
        void selectOption(int option);
    }

    //default constructor
    public Menu(){
        itemList = new ArrayList<>();
        sc = new Scanner(System.in);
        myListener = null;
    }//end constructor

    //set the menuListener
    //set up relationship from outside class
    public void setMenuListener(MenuListener listener){
        myListener = listener;
    }

    public void printMenu(){
        for(MenuItem item : itemList){
            System.out.println(item);
        }
        System.out.println();
    }//end method

    public void addMenuItem(MenuItem item){
        itemList.add(item);
    }//end method

    public void startMenu(){
        int option = 0;

        printMenu();

        do{
            //get user input
            System.out.print("\nEnter your option or -1 to exit:");
            option = sc.nextInt();

            //process the user input
            if(myListener != null){
                //trigger the method from outside the class
                myListener.selectOption(option);
            }

        }while(option!=-1);
    }//end method
}//end class
