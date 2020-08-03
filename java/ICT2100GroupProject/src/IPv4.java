import java.util.InputMismatchException;

public class IPv4 {
    //private variable of 4 bytes
    private int byte1;
    private int byte2;
    private int byte3;
    private int byte4;

    /**
     * Default constructor which create IPv4 object with initial value of 0.0.0.0
     */
    public IPv4(){
        this(0,0,0,0);
    }

    /**
     * The overloaded constructor when the input is 4 integer value(enter block by block)
     * @param byte1 the 1st block of IPv4
     * @param byte2 the 2nd block of IPv4
     * @param byte3 the 3rd block of IPv4
     * @param byte4 the 4th block of IPv4
     */
    public IPv4(int byte1,int byte2,int byte3,int byte4){
        setByte1(byte1);
        setByte2(byte2);
        setByte3(byte3);
        setByte4(byte4);
    }

    /**
     * The overloaded constructor when the input is a String(enter whole IP in String format)
     * Provide validation by split the String with "."
     * If the String cannot be divided into 4 block, an InputMismatchException will be thrown.
     * @param ip The String of IPv4
     */
    public IPv4(String ip){
        //split the String input by "."
        String[] block = ip.split("\\.");

        //check if the String can be split into 4 block
        if(block.length!= 4)
            throw new InputMismatchException();

        //set the bytes by parse the value of each block into Integer value
        setByte1(Integer.parseInt(block[0]));
        setByte2(Integer.parseInt(block[1]));
        setByte3(Integer.parseInt(block[2]));
        setByte4(Integer.parseInt(block[3]));
    }


    /**
     * The setter used to set the 1st byte block of IPv4
     * The input should have a value between 0 - 255 or value will be set to 0
     * @param byte1 the 1st block of IPv4
     */
    public void setByte1(int byte1){
        if(byte1<0||byte1>255)
            this.byte1 = 0;
        else
            this.byte1 = byte1;
    }
    /**
     * The setter used to set the 2st byte block of IPv4
     * The input should have a value between 0 - 255 or value will be set to 0
     * @param byte2 the 2nd block of IPv4
     */
    public void setByte2(int byte2){
        if(byte2<0||byte2>255)
            this.byte2 = 0;
        else
            this.byte2 = byte2;
    }
    /**
     * The setter used to set the 3st byte block of IPv4
     * The input should have a value between 0 - 255 or value will be set to 0
     * @param byte3 the 3rd block of IPv4
     */
    public void setByte3(int byte3){
        if(byte3<0||byte3>255)
            this.byte3 = 0;
        else
            this.byte3 = byte3;
    }
    /**
     * The setter used to set the 4st byte block of IPv4
     * The input should have a value between 0 - 255 or value will be set to 0
     * @param byte4 the 4th block of IPv4
     */
    public void setByte4(int byte4){
        if(byte4<0||byte4>255)
            this.byte4 = 0;
        else
            this.byte4 = byte4;
    }

    //getter

    /**
     * Getter which return the value of 1st block of IPv4
     * @return value of 1st block of IPv4 in range 0 - 255
     */
    public int getByte1(){return this.byte1;}
    /**
     * Getter which return the value of 2nd block of IPv4
     * @return value of 2nd block of IPv4 in range 0 - 255
     */
    public int getByte2(){return this.byte2;}
    /**
     * Getter which return the value of 3rd block of IPv4
     * @return value of 3rd block of IPv4 in range 0 - 255
     */
    public int getByte3(){return this.byte3;}
    /**
     * Getter which return the value of 4th block of IPv4
     * @return value of 4th block of IPv4 in range 0 - 255
     */
    public int getByte4(){return this.byte4;}

    /**
     * This method will combine the byte blocks of the object and return the String of IPv4
     * @return String of IPv4
     */
    @Override
    public String toString(){return byte1+"."+byte2+"."+byte3+"."+byte4;}

    /**
     * This method will compare if the param has the same value as the object
     * The value is compared block by block after the class of the param is confirmed
     * @param obj The object to be compare
     * @return The result of comparison
     */
    @Override
    public boolean equals(Object obj){
        //check if obj is instance of the IPv4 class
        if(!(obj instanceof IPv4)){
            return false;
        }

        IPv4 temp = (IPv4) obj;
        boolean isEqual = true;

        //compare block by block
        if(temp.getByte1() != this.getByte1())
            isEqual = false;
        else if(temp.getByte2() != this.getByte2())
            isEqual = false;
        else if(temp.getByte3() != this.getByte3())
            isEqual = false;
        else if(temp.getByte4() != this.getByte4())
            isEqual = false;

        return isEqual;
    }
}
