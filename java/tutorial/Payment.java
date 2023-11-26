public abstract class Payment{
    protected int receiptID;
    protected double purchaseAmount;

    Payment(){
        receiptID = 0;
        purchaseAmount = 0.0;
    }

    public void displayInfo(){
        System.out.println(receiptID + " : " + purchaseAmount);
    }

    public void setReceiptID(int receiptID){
        this.receiptID = receiptID;
    }

    public void setPurchaseAmount(double purchaseAmount){
        this.purchaseAmount = purchaseAmount;
    }

    public int getReceiptID(){
        return this.receiptID;
    }

    public double getPurchaseAmount(){
        return this.purchaseAmount;
    }

    public abstract double calculateGrandTotal();
}

public interface Taxable{

}