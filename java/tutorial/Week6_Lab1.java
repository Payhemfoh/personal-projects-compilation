/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Payhemfoh
 */
public class Week6_Lab1 {
    public static void main(String args[]){
        System.out.println("Celsius" + "\t" + "Fahrenheit");
        for (int cels = 10; cels <= 30; cels++)
             cToF(cels);
    }
    public static void cToF(double cels){
        double fahr = cels * (5.0/9.0) + 32;
        System.out.printf("%.2f\t ->%.2f\n", cels,fahr);
    }
}
