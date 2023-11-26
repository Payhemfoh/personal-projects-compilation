import java.util.ArrayList;
import java.util.Scanner;
import java.util.ArrayList;


public class ComputeRestTime {
    public static void main(String[] args){
        int totalDays = 0, totalRest = 0, maxRest = 0;
        Scanner sc = new Scanner(System.in);
        ArrayList<Ball> list = new ArrayList<>();

        totalDays = sc.nextInt();
        totalRest = sc.nextInt();

        boolean[] working = new boolean[totalDays];
        for(int i=0;i<working.length;++i){
            working[i] = getWorkingInput();
        }
    
        //logic
        /*
            replace the rest one by one while the remain
            day is equals or more than the total rest day

            then calculate the consecutive rest day

            find the maximum consecutive rest day by repeating
         */


        for(int i=0;i<=working.length-totalRest;++i){
            //create temp working time
            boolean[] temp = new boolean[totalDays];
            for(int j=0;j<totalDays;++j)
                temp[j] = working[j];

            //get temp remain rest day(initialize to the total rest day)
            int remainRestDays = totalRest;

            //replace working day
            for(int j=i;j<totalDays;++j) {
                if(remainRestDays==0)
                    break;
                if(temp[j]){
                    temp[j] = false;
                    remainRestDays--;
                }
            }

            int count = 0;
            for(boolean work:temp){
                if(work){
                    count = 0;
                }else{
                    ++count;
                }
                if(count>maxRest)
                    maxRest = count;
            }
        }

        System.out.println(maxRest);
    }

    public static boolean getWorkingInput(){
        String input="";
        Scanner sc = new Scanner(System.in);

        do {
            input = sc.nextLine();
        }while(input.equals(""));

        boolean target = true;

        switch(input){
            case "work":
                target = true;
                break;
            case "off":
                target = false;
                break;
        }

        return target;
    }
}
