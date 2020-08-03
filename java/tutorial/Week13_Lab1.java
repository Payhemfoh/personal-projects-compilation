//recursive demo 1
public class Week13_Lab1 {
    public static void main(String[] args){
        printNo2(1,10);
    }

    //print out 1 to 10 with a method(iterating approach)
    public static void printNo(int start,int stop){
        for(int i=start;i<=stop;++i){
            System.out.print(i+" ");
        }
        System.out.println();
    }

    //print out 1 to 10 with a method(recursive)
    public static void printNo2(int start,int stop){
        //base case to end
        if(stop < start){
            return;
        }
        printNo2(start+1,stop);
        System.out.print(start+" ");

    }
}
