import java.util.Scanner;

public class Week8_Lab3 {
    public static void main(String[] args){
        Painting p1=new Painting();

        Painting p2=new Painting("Sono chi no sadame Jo~~~~~Jo","Jotaro Joestar","Water Colour",2200);
        Painting p3=new Painting(p2);
        Painting p4=p2;
        input(p1);
        input(p2);
        System.out.printf("%s\n%s\n%s\n%s\n",p1,p2,p3,p4);


        p3.setPrice(1100);
        p4.setPrice(4000);
        System.out.printf("%s\n%s\n%s\n%s\n",p1,p2,p3,p4);
    }
    private static void input(Painting p){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter title:");
        String title=sc.nextLine();
        System.out.print("Enter artist:");
        String artist=sc.nextLine();
        System.out.print("Enter medium:");
        String medium=sc.nextLine();
        System.out.print("Enter price:");
        double price=sc.nextDouble();

        p.setTitle(title);
        p.setArtist(artist);
        p.setMedium(medium);
        p.setPrice(price);
    }
}

class Painting{
    private String title;
    private String artist;
    private String medium;
    private double price;
    private double commission;

    public Painting(){
        title="";
        artist="";
        medium="";
        price=0.0;
        commission=0.0;
    }

    public Painting(String title,String artist,String medium,double price){
        this.title=title;
        this.artist=artist;
        this.medium=medium;
        this.price=price;
        this.commission=commission;
    }

    public Painting(Painting obj){
        this.title=obj.getTitle();
        this.artist = obj.getArtist();
        this.medium = obj.getMedium();
        setPrice(obj.getPrice());
    }

    //getter
    public String getTitle(){ return title; }
    public String getArtist(){return artist;}
    public String getMedium(){return medium;}
    public double getPrice(){return price;}
    public double getCommission(){return commission;}

    //setter
    public void setArtist(String artist) { this.artist = artist; }
    public void setTitle(String title){this.title = title;}
    public void setMedium(String medium){this.medium = medium;}
    public void setPrice(double price) {
        if (price > 0) {
            this.price = price;
            this.commission = price*0.2;
        }
    }

    @Override
    public String toString(){
        return "Title:"+title+"\nArtist:"+artist+"\nMedium:"+medium+String.format("\nPrice:%.2f",price)+String.format("\nCommission:%.2f\n",commission);
    }


}