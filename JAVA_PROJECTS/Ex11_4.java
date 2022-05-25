import java.awt.Container;
import java.awt.FlowLayout;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;

public class Ex11_4 extends JFrame{
    public Ex11_4() {
        this.setTitle("체크박스예제 20202856 최혁진");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container con = this.getContentPane();
        con.setLayout(new FlowLayout());
        JCheckBox cb_apple = new JCheckBox("사과");
        JCheckBox cb_bae = new JCheckBox("배",true);
        con.add(cb_apple); con.add(cb_bae);

        ImageIcon Icon = new ImageIcon("cherry2.png");
        JCheckBox cb_cherry = new JCheckBox("체리",Icon);
        con.add(cb_cherry);

        JButton btn = new JButton("Ok");
        con.add(btn);

        this.setSize(250,150);
        this.setVisible(true);
    }
    public static void main(String[] args) {
        new Ex11_4();
    }
}
