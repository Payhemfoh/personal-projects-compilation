import javax.swing.JOptionPane;
import java.io.*;

public class Week9_Lab4 {
    public static void main(String[] args) throws IOException{
        final int SIZE=20;
        int[] number = new int[SIZE];

        int n = getInput(number);

        System.out.println("You have "+n+" number in the list");

        int smallest = getSmallest(number,n);
        int largest = getLargest(number,n);
        double average = getAverage(number,n);

        System.out.printf("Smallest:%d\nLargest:%d\nAverage%.2f",number[smallest],number[largest],average);

        saveList(number,n);
    }

    public static int getInput(int[] numbers)
    {
        String input;
        int count = 0, n;

        // read ahead
        input = JOptionPane.showInputDialog(
                "Enter a number\nTerminate with -ve number");
        n = Integer.parseInt(input);

        while (n >= 0)
        {
            if(count == numbers.length){
                System.out.println("Maximum size reached!");
                break;
            }

            numbers[count] = n;
            count++;
            input = JOptionPane.showInputDialog(
                    "Enter a number\nTerminate with -ve number");
            n = Integer.parseInt(input);
        }
        return count;
    }

    public static int getSmallest(int[] numbers,int size){
        int smallest=numbers[0];
        int pos=0;
        for(int i=1;i<size;i++) {
            if (numbers[i] < smallest){
                pos = i;
                smallest = numbers[i];
            }
        }
        return pos;
    }

    public static int getLargest(int[] numbers,int size){
        int largest=numbers[0];
        int pos=0;
        for(int i=1;i<size;i++){
            if(numbers[i]>largest) {
                pos = i;
                largest = numbers[i];
            }
        }
        return pos;
    }

    public static double getAverage(int[] numbers,int size){
        int total=0;
        for(int i=0;i<size;i++){
            total+=numbers[i];
        }
        return 1.0*total/size;
    }

    private static void saveList(int number[],int size) throws IOException{
        FileWriter fw = new FileWriter("number.txt");
        PrintWriter pw = new PrintWriter(fw);

        for(int x:number){
            pw.println(x);
        }

        pw.close();
    }
}
