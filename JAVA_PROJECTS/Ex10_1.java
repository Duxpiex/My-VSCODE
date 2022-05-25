import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class Ex10_1 extends JFrame {
    public Ex10_1() {
        this.setTitle("이벤트처리1 ");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container con = this.getContentPane();
        con.setLayout(new FlowLayout());

        JButton btn1 = new JButton("Action");
        JButton btn2 = new JButton("Cancle");
        con.add(btn1); con.add(btn2);

        
        MyActionListener lis = new MyActionListener();
        btn1.addActionListener(lis);

        this.setSize(350,150);
        this.setVisible(true);
    }
    public static void main(String[] args) {
        new Ex10_1();
    }
}

class MyActionListener implements ActionListener {
    @Override
    public void actionPerformed(ActionEvent e) {
        System.out.println(e);
        System.out.println("Action button 클릭~");
        JButton b = (JButton) e.getSource();
        if (b.getText().equals("Action"))
            b.setText("액션");
        else
            b.setText("Action");
    }
}

