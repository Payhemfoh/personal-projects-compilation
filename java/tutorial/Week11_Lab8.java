import java.time.*;
import java.time.format.*;
import java.util.Random;

public class Week11_Lab8 {
    public static void main(String[] args){
        LocalDate today = LocalDate.now();
        LocalDate aprilFool = LocalDate.of(2020,4,1);

        System.out.println("Today:"+today);

        DateTimeFormatter format = DateTimeFormatter.ofPattern("dd-MM-yyyy");

    }
}

class TestRdn{
    public static void main(String args[]) {
        Random random1 = new Random();
        System.out.println("Form random1:");

        for (int i = 0; i < 10; ++i) {
            System.out.println(random1.nextInt(100));
        }
    }
}