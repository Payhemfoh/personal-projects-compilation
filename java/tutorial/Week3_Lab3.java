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

public class Week3_Lab3 {
    public static void main(String args[]){
        double thai=0.0,rm=0.0;
        final double RM_TO_BHAT = 7.5;
        //get input from user
        String RMString=JOptionPane.showInputDialog(null,"Enter number of RMs","money converter",JOptionPane.QUESTION_MESSAGE);
        //Wrapper class is a special class for initive data type
        rm=Double.parseDouble(RMString);
        //calculation
        thai = rm*7.5;
        //format the output
        String output = "RM "+String.format("%.2f",rm)+" = "+String.format("%.2f",thai)+" Bhat";
        
        JOptionPane.showMessageDialog(null, "RM "+RMString+" = "+thai+" Bhat","Transvert result",JOptionPane.INFORMATION_MESSAGE);
    }
}
