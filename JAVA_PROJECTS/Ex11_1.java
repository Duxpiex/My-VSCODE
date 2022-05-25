import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class Ex11_1 extends JFrame{
    public Ex11_1() {
        this.setTitle("이벤트처리1 ");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container con = this.getContentPane();
        con.setLayout(new FlowLayout());

        JButton btn1 = new JButton("빨강글자 노랑배경 버튼1");
        JButton btn2 = new JButton("비활성화 버튼2");
        JButton btn3 = new JButton("좌표 버튼3");
        con.add(btn1); con.add(btn2); con.add(btn3);
        btn1.setForeground(Color.RED);
        btn1.setBackground(Color.YELLOW);

        btn2.setEnabled(false);

        btn3.addActionListener(new ActionListener() {
           @Override
           public void actionPerformed(ActionEvent e) {
               JButton b = (JButton) e.getSource();
               System.out.println("x= " + b.getX() +", y = " + b.getY() + " " + b.getText());
           }
        });

        this.setSize(350,150);
        this.setVisible(true);

    }

    public static void main(String[] args) {
        new Ex11_1();
    }
}