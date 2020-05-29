/*
    The program get RGB color code input from user
    and convert into CMYK color code
 */
//import scanner class to track input
import java.util.Scanner;
import javax.swing.JOptionPane;

public class ConvertColorCode {

    //main method
    public static void main(String[] args) {

        //fixed value for the max value of RGB color code
        final float RGB_MAX = 255f;

        //declare variable for rgb color code
        int red = 0, green = 0, blue = 0;
        //declare variable for cmyk color code
        int cyan = 0, magenta = 0, yellow = 0, black = 0;
        float w = 0, c = 0, m = 0, y = 0, k = 0;
        //declare scanner class to get input
        Scanner input = new Scanner(System.in);

        //get input for rgb color code
        System.out.print("Please enter the value for Red color(0-255)\t:");
        red = input.nextInt();
        System.out.print("Please enter the value for Green color(0-255)\t:");
        green = input.nextInt();
        System.out.print("Please enter the value for Blue color(0-255)\t:");
        blue = input.nextInt();

        //find the w value
        w = Math.max(Math.max(red / RGB_MAX, green / RGB_MAX), blue / RGB_MAX);
        //calculate cmyk value
        if (w != 0) {
            c = (w - (red / RGB_MAX)) / w;
            m = (w - (green / RGB_MAX)) / w;
            y = (w - (blue / RGB_MAX)) / w;
            k = 1 - w;
        } else {
            c = 0;
            m = 0;
            y = 0;
            k = 1;
        }

        //convert value to 100%
        cyan = (int) (Math.round(c * 100));
        magenta = (int) (Math.round(m * 100));
        yellow = (int) (Math.round(y * 100));
        black = (int) (Math.round(k * 100));

        //format the output message
        String output = "RGB("
                + String.format("%d", red)
                + "," + String.format("%d", green)
                + "," + String.format("%d", blue)
                + ") = CMYK("
                + String.format("%d", cyan)
                + "," + String.format("%d", magenta)
                + "," + String.format("%d", yellow)
                + "," + String.format("%d", black) + ")";

        //display message box with the result
        JOptionPane.showMessageDialog(null, output, "Color Code Convertion Result", JOptionPane.INFORMATION_MESSAGE);
    }
}
