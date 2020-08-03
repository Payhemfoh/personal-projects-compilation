public class ExceptionMethodDemo2 {
    public static void main(String[] args){
        try {
            printNumber();
        }catch(RuntimeException e){
            System.out.println(e.getMessage());
        }catch(Exception e){
            System.out.println(e.getMessage());
        }
    }

    public static void printNumber(){
        for(int i=0;i<10;++i){
            if(i==7)
                throw (new RuntimeException("I dont like 7"));
            System.out.println(i);
        }
    }
}
