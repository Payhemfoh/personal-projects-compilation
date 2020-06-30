public class Week8_Lab2 {
    public static void main(String[] args){
        
    }
}

class Sandwich{
    private String ingredient;
    private String bread;
    private double price;

    public Sandwich(){
        ingredient="";
        bread="";
        price=0.0;
    }

    public void setIngredient(String ingredient) { this.ingredient = ingredient; }
    public void setBread(String bread){ this.bread = bread; }
    public void setPrice(double price) { this.price = price; }

    public String getIngredient(){return ingredient;}
    public String getBread(){return bread;}
    public double getPrice(){return price;}
}
