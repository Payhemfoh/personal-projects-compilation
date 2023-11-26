import java.util.Scanner;

public class Assignment_1 {

    public static void showMenu() {
        System.out.printf("%-3s|%-40s|%-10s\n|", "No", "Item", "Price");
        System.out.println("------------------------------------------------------------------");
        System.out.printf("%-3d|%-40s|RM %-7.2f\n", 1, "Coffee", 1.80);
        System.out.printf("%-3d|%-40s|RM %-7.2f\n", 2, "Soft drink", 2.0);
        System.out.printf("%-3d|%-40s|RM %-7.2f\n", 3, "Dessert", 3.50);
        System.out.printf("%-3d|%-40s|RM %-7.2f\n", 4, "Starter", 4.0);
        System.out.printf("%-3d|%-40s|RM %-7.2f\n", 5, "Main Course", 8.0);
        System.out.printf("%-3d|%-40s|RM %-7.2f\n", 6, "Main Course + Dessert", 11.0);
        System.out.printf("%-3d|%-40s|RM %-7.2f\n", 7, "Main Course + Starter", 11.50);
        System.out.printf("%-3d|%-40s|RM %-7.2f\n", 8, "Combo (Main Course + Starter + Dessert", 15.0);

    }

    /**
     * This method will accept the integer input from user and validate the input
     * @return the integer input of the user
     */
    public static int choice() {
        Scanner input = new Scanner(System.in);
        boolean isvalid = false;
        int number = 0;
        do {
            System.out.print("Enter your choice : ");
            number = input.nextInt();
            if (number >= 1 && number <= 8) {
                isvalid = true;
            } else {
                System.out.println("Invalid Number! Please enter again");
            }
        } while (!isvalid);
        return number;
    }

    public static boolean next() {
        Scanner sc = new Scanner(System.in);
        boolean isvalid = false;
        boolean result = false;
        String order = "";
        do {
            System.out.print("Do you want to order next item [Y/N] : ");
            order = sc.nextLine().trim();
            System.out.println(order);
            if (order.equalsIgnoreCase("Y") || order.equalsIgnoreCase("N")) {
                isvalid = true;
            } else {
                System.out.println("Invalid choice! Please enter again : ");
            }
        } while (!isvalid);

        if (order.equalsIgnoreCase("Y")) {
            result = true;
        }

        return result;
    }

    /**
     * This method will print the order detail
     * @param name the name of the order item
     * @param qty the quantity of the item
     * @param price the unit price of item
     */
    public static void printDetails(String name, int qty, double price) {
        if (qty > 0) {
            System.out.printf("%-40s RM %-7.2f %-3d RM %-7.2f", name, price, qty, price * qty);
        }
    }

    public static void main(String args[]) {
        int freecoffee = 0;
        int freesoftdrink = 0;
        int coffee = 0;
        int softdrink = 0;
        int dessert = 0;
        int starter = 0;
        int mc = 0;
        int mcd = 0;
        int mcs = 0;
        int combo = 0;
        double totalprice = 0.0;

        boolean ifcontinue = true;
        do {
            showMenu();
            int number = choice();
            switch (number) {
                case 1:
                    coffee++;
                    totalprice += 1.8;
                    break;
                case 2:
                    softdrink++;
                    totalprice += 2.0;
                    break;
                case 3:
                    dessert++;
                    totalprice += 3.5;
                    break;
                case 4:
                    starter++;
                    totalprice += 4.0;
                    break;
                case 5:
                    mc++;
                    totalprice += 8.0;
                    break;
                case 6:
                    mcd++;
                    totalprice += 11.0;
                    freecoffee++;
                    break;
                case 7:
                    mcs++;
                    totalprice += 11.5;
                    freesoftdrink++;
                    break;
                case 8:
                    combo++;
                    totalprice += 15.0;
                    freecoffee++;
                    freesoftdrink++;
                    break;

            }
            
            
                ifcontinue = next();
            
        } while (ifcontinue);

        totalprice = (1.8 * coffee) + (2.0 * softdrink) + (3.5 * dessert) + (4.0 * starter)
                + (8.0 * mc) + (11.0 * mcd) + (11.5 * mcs) + (15.0 * combo);

        //print the order receipt
        System.out.printf("Order\n");
        System.out.println("-------------------------------------");
        printDetails("Coffee", coffee, 1.8);
        printDetails("Soft Drink", softdrink, 2.0);
        printDetails("Dessert", dessert, 3.5);
        printDetails("Starter", starter, 4.0);
        printDetails("Main Course", mc, 8.0);
        printDetails("Main Course + Dessert", mcd, 11.0);
        printDetails("Main Course + Starter", mcs, 11.5);
        printDetails("Combo(Main Course + Starter + Dessert)", combo, 15.0);
        System.out.printf("*free %d soft drink", freesoftdrink);
        System.out.printf("*free %d coffee", coffee);
        System.out.println("-------------------------------------");
        System.out.printf("%53s RM %-7.2f", "", totalprice);
        System.out.println("-------------------------------------");

    }//end main

}//end class
