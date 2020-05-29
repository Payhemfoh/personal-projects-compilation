/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Payhemfoh
 */
import javax.swing.JOptionPane;

//AWT abstract window toolkey
//SWING
//Java FX
public class Week3_Lab2 {
    public static void main(String args[]){
        String name="";
        //show box to get name
        name=JOptionPane.showInputDialog("Enter Your Name:");
        
        //display name to user
        //JOptionPane.showMessageDialog(null,"Hello and Welcome\n"+name);
        JOptionPane.showMessageDialog(null, "Hello and welcome\n"+name,
                                                                            "Welcome", JOptionPane.WARNING_MESSAGE);
    }
}
