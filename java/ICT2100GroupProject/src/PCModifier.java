public interface PCModifier {
    int COMPUTERLISTSIZE = 50;
    void addPC(PC temp);
    void removePC(PC temp);
    void removePC(int index);
    boolean hasPC(PC temp);
    PC getPC(PC temp);
    PC getPC(int index);
    int getComputerPos(PC temp);
    int getNumComputer();
    void printComputerList();
}//end interface
