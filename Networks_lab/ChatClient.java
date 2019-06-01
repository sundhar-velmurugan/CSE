import java.net.*;
import java.io.*;
import javax.swing.*;
import java.awt.event.*;

public class ChatClient extends JFrame implements ActionListener{

	JPanel jpanel;
	JButton jbutton;
	JTextField jtextfield;
	JTextArea jtextarea;
	Socket soc;
	
	public ChatClient()throws Throwable{
		jpanel = new JPanel();
		jtextarea = new JTextArea();
		jtextfield = new JTextField();
		jbutton = new JButton("click");
	
		this.setVisible(true);
		this.setSize(500,500);
		this.setTitle("client");
		
		jpanel.setLayout(null);
		jtextarea.setBounds(20,20,450,350);
		jtextfield.setBounds(20,470,350,30);
		jbutton.setBounds(390,470,90,30);
		
		this.add(jpanel);
		jpanel.add(jtextarea);
		jpanel.add(jtextfield);
		jpanel.add(jbutton);
		
		jbutton.addActionListener(this);
		soc = new Socket("localhost",2999);
		jtextarea.setText("Found Server");
		while(true){
			BufferedReader buffer = new BufferedReader(new InputStreamReader(soc.getInputStream()));	
			String temp = buffer.readLine();
			jtextarea.setText(jtextarea.getText()+"\nserver:"+temp);
		}
	
	}
	
	public void actionPerformed(ActionEvent e){
	
		if((e.getSource()==jbutton) && (jtextfield.getText()!="")){
		
			try{
				jtextarea.setText(jtextarea.getText()+"\nme:"+jtextfield.getText());
				PrintStream ps = new PrintStream(soc.getOutputStream());
				ps.println(jtextfield.getText());
			
			}catch(Exception e1){}
			jtextfield.setText("");
			
		}
		
	}
	

	public static void main(String[] args)throws Throwable{
		new ChatClient();
	
	}


}
