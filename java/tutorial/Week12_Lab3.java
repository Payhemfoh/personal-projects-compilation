import javax.swing.*;
import java.awt.*;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Week12_Lab3 {
    public static void main(String[] args){
        String input = "";
        double value = 0.0;
        boolean isValid = true;

        do {
            //Task 1 prompt user to enter a double value with input dialog
            input = JOptionPane.showInputDialog("Please enter a double value");

            try {
                //convert input value to double
                value = Double.parseDouble(input);
                isValid = true;
            } catch (NumberFormatException | NullPointerException e) {
                JOptionPane.showMessageDialog(null,"Invalid input:"+e.getMessage(),"Error",JOptionPane.ERROR_MESSAGE);
                isValid = false;
            } catch(Exception e){
                JOptionPane.showMessageDialog(null,"Oops! An unexpected error had occur during the process "+e.getMessage(),"Error",JOptionPane.ERROR_MESSAGE);
            }
        }while(!isValid);

        JOptionPane.showMessageDialog(null,String.format("The value you entered is %.2f\n",value));
    }
}

class Week12_Lab3_Ver2{
    public static void main(String[] args) {
        String input = "";
        double radius = 0.0;
        boolean isValid = false;
        do {
            try {
                input = JOptionPane.showInputDialog("Enter a circle radius:");

                radius = Double.parseDouble(input);

                if(radius == 0)
                    throw new InputMismatchException("Input of radius = 0");

                double area = Math.PI * radius * radius;
                isValid = true;
                JOptionPane.showMessageDialog(null, String.format("The circle area is: %.2f",area));

            } catch (NumberFormatException | InputMismatchException e) {
                JOptionPane.showMessageDialog(null, "Invalid Input " + e.getMessage(), "Error", JOptionPane.WARNING_MESSAGE);
            } catch(NullPointerException e){
                JOptionPane.showMessageDialog(null,"The program will be exit!");
                isValid = true;
            }
            catch (Exception e){
                JOptionPane.showMessageDialog(null,"An unexpected error had occur when the program is running.","Error",JOptionPane.ERROR_MESSAGE);
            }
        }while(!isValid);
    }
}