public class Week5_Lab1{
    public static void main(String[] args){
         System.out.printf("%4s\t%4s\t%4s\t\n","No","No^2","No^3");
        for(int i=1;i<11;i++){
            System.out.printf("%4d\t%4d\t%4d\n",i,i*i,i*i*i);
        }
        
        int i=1;
        System.out.printf("\n\n\n%4s\t%4s\t%4s\t\n","No","No^2","No^3");
        while(i<11){
            System.out.printf("%4d\t%4d\t%4d\n",i,i*i,i*i*i);
            i++;
        }
        
        i=1;
         System.out.printf("\n\n\n%4s\t%4s\t%4s\t\n","No","No^2","No^3");
        do{
            System.out.printf("%4d\t%4d\t%4d\n",i,i*i,i*i*i);
            i++;
        }while(i<11);
    }
}