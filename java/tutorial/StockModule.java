import java.util.ArrayList;
import javax.swing.JOptionPane;

public class StockModule {
    private ArrayList<Product> list;

    public StockModule(){
        list = new ArrayList<>();

        for(int i=1;i<=20;++i)
            list.add(new Product("IPHONE "+i,100*i));
    }

    public StockModule(ArrayList<Product> list){
        this.list = list;
    }

    /**
     * Wo CAO Ni MA
     */
    private void printMainMenu(){
        System.out.println("........");
    }

    /**
     * Hello mother fucker
     */
    public void processMainMenu(){
        boolean isContinue = true;
        int option = 0;

        do{
            printMainMenu();
            option = Integer.parseInt(JOptionPane.showInputDialog("Option"));

            switch(option){
                case 1:
                    addProduct();
                    break;
                case 2:
                    editProduct();
                    break;
                case 3:
                    deleteProduct();
                    break;
                case 4:
                    displayProduct();
                    break;
                case 5:
                    isContinue = false;
                    System.out.println("Returning to Main Module...");
                    break;
                default:
                    System.out.println("Invalid input, Please try again!");
            }
        }while(isContinue);
    }

    private void deleteProduct(){
            boolean isContinue = true;

            do {
                int size = list.size();
                System.out.println("Index |Name");
                System.out.println("---------------------------------------");
                for (int i = 0; i < size; ++i) {
                    System.out.printf("%-5d|%-30s\n", i + 1, list.get(i).getName());
                }
                System.out.println("---------------------------------------");
                System.out.printf("Enter %d to return to menu\n",size+1);

                int option = 0;
                option = Integer.parseInt(JOptionPane.showInputDialog("Option"));


                if (option > 0 && option <= size) {
                    Product ptr = list.get(option - 1);


                    System.out.println(ptr);

                    char answer = JOptionPane.showInputDialog("Are you sure you want to delete?[Y/N]").charAt(0);
                    switch(answer){
                        case 'y':
                        case 'Y':
                            list.remove(option-1);
                            System.out.println("The Object had been removed.");
                            break;
                        case 'N':
                        case 'n':
                            System.out.println("The Object did not removed.");
                            break;
                        default:
                            System.out.println("Invalid Input!The Object did not removed.");
                    }


                } else if (option == size + 1) {
                    System.out.println("Return");
                    isContinue = false;
                } else {
                    System.out.println("Invalid Input!");
                }
            }while(isContinue);
    }


    private void addProduct() {
        String name="";
        double price=0.0;
        int type=0;


        name = JOptionPane.showInputDialog("Enter name:");
        price = Double.parseDouble(JOptionPane.showInputDialog("Enter Price:"));

        System.out.println("1 -> SmartPhone\n2 -> Tablet");
        type=Integer.parseInt(JOptionPane.showInputDialog("Enter type of product:"));
        switch(type){
            case 1:
                //list.add(new SmartPhone());
                break;
            case 2:
                //list.add(new Tablet());
                break;
        }

        System.out.println("The product had been added successfully.");
    }

    private void editProduct(){
        final int SIZE = list.size();
        boolean isContinue = true;

        do {
            System.out.println("Index |Name");
            System.out.println("---------------------------------------");
            for (int i = 0; i < SIZE; ++i) {
                System.out.printf("%-5d|%-30s\n", i + 1, list.get(i).getName());
            }
            System.out.println("---------------------------------------");
            System.out.printf("Enter %d to return to menu\n",SIZE+1);

            int option = 0;
            option = Integer.parseInt(JOptionPane.showInputDialog("Option"));


            if (option > 0 && option <= SIZE) {
                Product ptr = list.get(option - 1);
                boolean innerLoop = true;

                do {
                    System.out.println(ptr);

                    //print menu for choice
                    System.out.println("1->Name\n2->Price");
                    int choice = Integer.parseInt(JOptionPane.showInputDialog("Enter choice:"));

                    switch (choice) {
                        case 1:
                            String name = JOptionPane.showInputDialog("Enter new Name:");

                            for(Product p:list)
                                if(name.equals(p.getName()))
                                    throw new AssertionError();

                            //ptr.setName(name);
                            break;
                        case 2:
                        //.../
                        case 3:
                            innerLoop = false;
                            break;
                        default:
                            System.out.println("Invalid input!");
                    }

                }while(innerLoop);



            } else if (option == SIZE + 1) {
                System.out.println("Return");
                isContinue = false;
            } else {
                System.out.println("Invalid Input!");
            }
        }while(isContinue);
    }



    private void displayProduct(){
        final int SIZE = list.size();
        boolean isContinue = true;

        do {
            System.out.println("Index |Name");
            System.out.println("---------------------------------------");
            for (int i = 0; i < SIZE; ++i) {
                System.out.printf("%-5d|%-30s\n", i + 1, list.get(i).getName());
            }
            System.out.println("---------------------------------------");
            System.out.printf("Enter %d to return to menu\n",SIZE+1);

            int option = 0;
            option = Integer.parseInt(JOptionPane.showInputDialog("Option"));


            if (option > 0 && option <= SIZE) {
                Product ptr = list.get(option - 1);

                System.out.println(ptr);
            } else if (option == SIZE + 1) {
                System.out.println("Return");
                isContinue = false;
            } else {
                System.out.println("Invalid Input!");
            }
        }while(isContinue);
    }
}


class Product{
    private String name;
    private double price;

    protected Product(String name,double price){
        this.name = name;
        this.price = price;
    }

    protected String getName(){return name;}

    @Override
    public String toString(){
        return "";
    }
}

/*
class Main {
    public static void main(String[] args){
        StockModule sm = new StockModule();
        sm.processMainMenu();
    }
}
 */