import javax.swing.JOptionPane;

public class RecursiveWindowMessage {
    public static void main(String[] args){
        createWindow(5);
    }

    public static void createWindow(int num){
        if(num==0)
            return;
        JOptionPane jp = new JOptionPane();
        var dialog = jp.createDialog(null,"Hello");
        dialog.setModal(false);
        dialog.setVisible(true);
        createWindow(--num);
        JOptionPane.showMessageDialog(null,"Hello");
        createWindow(num);
        System.out.println();
    }
}
