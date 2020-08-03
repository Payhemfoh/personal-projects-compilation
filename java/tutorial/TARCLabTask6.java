public class TARCLabTask6 {
}

class Account{
    private int accountNo;
    private String accountHolderName;
    private double accountBalance;
    private static double annualInterestRate;

    public Account(int accountNo,String name,double balance){
        this.accountNo = accountNo;
        this.accountHolderName = name;
        this.accountBalance = balance;
    }

    public void setAccountBalance(double accountBalance) {
        this.accountBalance = accountBalance;
    }

    public void setAccountHolderName(String accountHolderName) {
        this.accountHolderName = accountHolderName;
    }

    public void setAccountNo(int accountNo) {
        this.accountNo = accountNo;
    }

    public int getAccountNo() {
        return accountNo;
    }

    public String getAccountHolderName(){return this.accountHolderName;}

    public double getAccountBalance() {
        return accountBalance;
    }

    public static void setAnnualInterestRate(double rate){
        annualInterestRate = rate;
    }

    public static double getAnnualInterestRate(){return annualInterestRate;}

    public void cashIn(double cash){
        this.accountBalance+=cash;
    }

    public void cashOut(double cash){
        this.accountBalance-=cash;
    }

    public double calculateInterest(){
        return this.accountBalance * annualInterestRate;
    }

    @Override
    public String toString(){
        return String.format("AccountNo: %d,Account Holder Name: %s,Account Balance: %.2f," +
                            "Annual Interest Rate: %.2f",this.accountNo,this.accountHolderName,
                            this.accountBalance,annualInterestRate);
    }
}

class FixedDepositAccount extends Account{
    private int savingYears;

    public FixedDepositAccount(int accountNo,String name,double balance,int savingYears){
        super(accountNo,name,balance);
        this.savingYears = savingYears;
    }

    public void setSavingYears(int savingYears){this.savingYears = savingYears;}
    public int getSavingYears(){return this.savingYears;}

    @Override
    public double calculateInterest(){
       return super.getAccountBalance() * getAnnualInterestRate() * this.savingYears;
    }

    @Override
    public String toString(){
        return "Account Number :"+super.getAccountNo()+
                "\nAccount Holder Name :"+super.getAccountHolderName()+
                "\nAccount Balance :"+super.getAccountBalance();
    }
}

class OverdraftAccount extends Account{
    private String accountType;
    private double overdraftLimit;
    private double overdraftInterestRate;

    public OverdraftAccount(int accountNo,String name,double balance,String type){
        super(accountNo,name,balance);
        setAccountType(type);
    }

    public void setAccountType(String accountType) {
        this.accountType = accountType;
        if(accountType.equals("Premium")){
            overdraftInterestRate = 0.05;
            overdraftLimit = 10000;
        }else if(accountType.equals("Gold")){
            overdraftInterestRate = 0.065;
            overdraftLimit = 5000;
        }else if(accountType.equals("Silver")){
            overdraftInterestRate = 0.1;
            overdraftLimit = 2000;
        }
    }

    public String getAccountType(){return this.accountType;}

    public double getOverdraftLimit() {
        return overdraftLimit;
    }

    public double getOverdraftInterestRate() {
        return overdraftInterestRate;
    }

    @Override
    public void cashOut(double cash){
        double withdrawal = super.getAccountBalance() - cash;
        if(withdrawal < -this.overdraftLimit){
            System.out.println("Withdrawal fail");
        }else{
            super.setAccountBalance(withdrawal);
            System.out.println("Withdrawal Success.");
        }
    }

    @Override
    public double calculateInterest(){
        return super.getAccountBalance() * this.overdraftInterestRate;
    }

    @Override
    public String toString(){
        return "Account Number :"+super.getAccountNo()+
                "\nAccount Holder Name :"+super.getAccountHolderName()+
                "\nAccount Balance :"+super.getAccountBalance();
    }
}
