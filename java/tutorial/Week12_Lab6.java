public class Week12_Lab6 {
    public static void main(String args[]){
        C1 obj = new C1();
        System.out.println(obj.get());
    }
}

class A1{
    private int num;
    public A1(){num=10;}
    public int getNum(){return num;}
}

class B1 extends A1{
    public int getNumber(){
        return getNum();
    }
}

class C1 extends B1{
    public int get(){return super.getNumber();}
}