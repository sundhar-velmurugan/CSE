import java.awt.event.ActionListener;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JButton;

public class ex11 extends JFrame{
    JPanel jpanel;
    JButton jbutton;
    JTextArea jtext;
    JTextField jfield;
    
    public ex11() throws Throwable{
        jpanel = new JPanel();
        jbutton = new JButton("Send");
        jtext = new JTextArea();
        jfield = new JTextField();
        
        this.setVisible(true);
        this.setSize(800,600);
        this.setTitle("Sample");
        
        jpanel.setLayout(null);
        jtext.setBounds(20,20,420,360);
		jfield.setBounds(20,460,300,30);
		jbutton.setBounds(360,460,70,30);
        
        this.add(jpanel);
        jpanel.add(jtext);
        jpanel.add(jfield);
        jpanel.add(jbutton);
    }
    public static void main(String[] args)throws Throwable{
		new ex11();
	}
    
}