public interface SoftwareModifier {
    void printSoftwareList();
    void addSoftware(Software s);
    void removeSoftware(Software s);
    void removeSoftware(int index);
    boolean hasSoftware(Software s);
    Software getSoftware(Software s);
    Software getSoftware(int index);
    int getNumSoftware();
}//end interface
