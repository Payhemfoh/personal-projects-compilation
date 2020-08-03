public class Week11_Lab1 {
    
}

class Name{
    private String fName;
    private String lName;
    private String title;

    public Name(){ this("","",""); }
    public Name(String t,String f,String l){
        title =t;
        fName =f;
        lName =l;
    }

    public String getfName() { return fName; }

    public String getlName() { return lName; }

    public String getTitle() { return title; }

    public String getFullName(){
        return title+" "+fName+" "+lName;
    }

    public void setFName(String f){fName = f;}
    public void setLName(String l){lName = l;}
    public void setTitle(String t){title = t;}

    public void printData(){
        System.out.printf("Name: %s %s %s\n",title,fName,lName);
    }
}//end class

class Lecturer{
    private Name name;
    private Address address;
    private String id;
    private static int lecturerCount;

    public Lecturer(){
        name=new Name();
        address=new Address();
        id="";
        ++lecturerCount;
    }
    public Lecturer(Name n,Address a,String i){
        name =n;
        address=a;
        id=i;
        ++lecturerCount;
    }

    public Name getName(){return name;}
    public Address getAddress(){return address;}
    public String getId(){return id;}
    public static int getLecturerCount(){return lecturerCount;}

    public void setName(Name n){name =n;}
    public void setAddress(Address a){address=a;}
    public void setId(String i){id=i;}
    public void printData(){
        System.out.printf("Lecturer:\n%s\n%s\n%s\n",
                            name.getFullName(),
                            address.getFullAddress(),
                            id);
    }
}

class Address{
    private String street;
    private String town;
    private String postcode;

    public Address(){this("","","");}
    public Address(String s,String t,String p){
        street =s;
        town=t;
        postcode =p;
    }

    public String getStreet() { return street; }
    public String getTown(){return town;}
    public String getPostcode(){return postcode;}
    public String getFullAddress(){return street+", "+town+", "+postcode;}

    public void setStreet(String s){street = s;}
    public void setTown(String t){town =t;}
    public void setPostcode(String p){postcode =p;}
}

class TestLecturer{
    public static void main(String[] args){
        Name n1 = new Name("Mr","John","Smith");
        Address a1 = new Address("12 High Street","Newcastle","NE11NE");
        Lecturer john = new Lecturer(n1,a1,"123456");
        Lecturer j2 = new Lecturer(
                new Name("Mrs","John","Darvin"),
                new Address("14 Street","Cobble castle","DE14SE"),
                "986242");


        john.printData();
        j2.printData();
        System.out.printf("There are %d lecturers",Lecturer.getLecturerCount());
    }
}