import java.util.Scanner;

public class Week9_Lab1 {
    static final int SIZE = 5;
    public static void main(String[] args){

        int[] arr = {9,15,-23,4,10};
        for(int i:arr)
            System.out.println(i);

        int[] arr1 = new int[SIZE];
        inputList(arr1);
        for(int i=0;i<SIZE;i++){
            System.out.println("index "+i+" : "+arr[i]);
        }
        printReverseList(arr1);
    }

    public static void inputList(int[] list){
        Scanner sc = new Scanner(System.in);
        for(int i=0;i<SIZE;i++){
            list[i]=sc.nextInt();
        }
    }

    public static void printReverseList(int[] list){
        for(int i=SIZE-1;i>=0;++i){
            System.out.println("index "+i+" : "+list[i]);
        }
    }
}