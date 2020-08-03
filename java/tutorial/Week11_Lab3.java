import org.intellij.lang.annotations.RegExp;

class Employee{
    private String id;
    private String name;
    private String role;
    private double salary;

    public Employee(){System.out.println("Hi Employee");}
}

class SalaryBasedEmployee extends Employee{
    public SalaryBasedEmployee(){System.out.println("Hi Salary Employee");}
}

class ContractBasedEmployee extends Employee{
    public ContractBasedEmployee(){System.out.println("Hi Contract Employee");}
}

class employeeDriver{
    public static void main(String[] args){
        SalaryBasedEmployee e1 = new SalaryBasedEmployee();

        ContractBasedEmployee e2 = new ContractBasedEmployee();
    }
}

class Baba{
    private String name;
    public Baba(String arg){name=arg;System.out.println("Baba come first...");}

    public String getName() {
        return name;
    }
}

class AhBoy extends Baba{
    public AhBoy(){super("boy");System.out.println("Ah Boy come first...");}
    public AhBoy(String arg){super("");}
}

class Testboy{
    public static void main(String[] args){
        AhBoy b = new AhBoy();
        System.out.println(b.getName());
    }
}

class A{
    @Override
    public String toString() {
        return "A object";
    }
}

class B extends A{
    @Override
    public String toString() {
        return super.toString()+"\nB object";
    }
}

class testAB{
    public static void main(String args[]){
        B b = new B();
        System.out.println(b);
    }
}