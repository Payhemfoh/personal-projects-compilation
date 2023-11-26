import java.util.Scanner;

public class lunchSellingDriver {
    public static void main(String[] args){
        String orderList="",promotionList="";
        printMenu();
        int option = chooseMenu();
        int promotion = checkPromotion(option);
        orderList = formatOrderList(orderList,option);
        if(promotion>0)
            promotionList = formatPromotionList(promotionList,promotion);
    }

    public static String formatOrderList(String orderList,int orderId){
        String food="";
        double price=0.0;

        switch(orderId){
            case 1:
                food="Coffee";
                price=1.8;
                break;
            case 2:
                food="Soft drink";
                price=2;
                break;
            case 3:
                food="Dessert";
                price=3.5;
                break;
            case 4:
                food="Starter";
                price=4;
                break;
            case 5:
                food="Main Course";
                price=8;
                break;
            case 6:
                food="Main Course + Dessert";
                price=11;
                break;
            case 7:
                food="Main Course + Starter";
                price=11.5;
                break;
            case 8:
                food="Combo (Main Course + Starter + Dessert)";
                price=15;
        }
        return orderList+=String.format("%-40s RM %-7.2f\n",food,price);
    }

    public static String formatPromotionList(String promotionList,int promotion){
        switch(promotion){
            case 1:
                promotionList +="* free 1 coffee \n";
                break;
            case 2:
                promotionList +="* free 1 soft drink \n";
                break;
            case 3:
                promotionList +="* free 1 coffee \n";
                promotionList +="* free 1 soft drink \n";
        }
        return promotionList;
    }

    public static int checkPromotion(int choice){
        int result = 0;
        switch(choice){
            case 6:
                result = 1;
                break;
            case 7:
                result = 2;
                break;
            case 8:
                result = 3;
                break;
        }
        return result;
    }

    public static int chooseMenu(){
        Scanner sc = new Scanner(System.in);
        int input = 0;
        boolean isValid = false;
        do{
            input = sc.nextInt();
            if(input>=1 && input<=7 )
                isValid = true;
        }while(isValid);

        return input;
    }

    public static void printMenu(){
        System.out.printf("%-3s|%-40s|%-10s\n","No","Item","Price");
        System.out.println("--------------------------------------------------");
        System.out.printf("%-3d|%-40s|RM %-7.2f\n",1,"Coffee",1.8);
        System.out.printf("%-3d|%-40s|RM %-7.2f\n",2,"Soft drink",2.0);
        System.out.printf("%-3d|%-40s|RM %-7.2f\n",3,"Dessert",3.5);
        System.out.printf("%-3d|%-40s|RM %-7.2f\n",4,"Starter",4.0);
        System.out.printf("%-3d|%-40s|RM %-7.2f\n",5,"Main Course",8.0);
        System.out.printf("%-3d|%-40s|RM %-7.2f\n",6,"Main Course + Dessert",11.0);
        System.out.printf("%-3d|%-40s|RM %-7.2f\n",7,"Combo (Main Course + Starter + Dessert)",15.0);
    }
}
