//shows exceptions caused by method invokes
public class ExceptionMethodDemo {
    public static void main(String[] args){
        try {
            a();
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Oops! Error occur during the process!"+e.getMessage());
        }catch(Exception e){
            System.out.println("Oops! Error occur during the process!"+e.getMessage());
        }


    }

    public static void a(){
        b();
    }

    public static void b(){
        c();
    }

    public static void c() {
        String text = "Do not give me error";

        for(int i=0;i<=text.length();++i){
            System.out.println(text.charAt(i));
        }
    }
}
