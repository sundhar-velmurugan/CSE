import java.io.*;
import java.net.*;
import javax.swing.*;
import java.awt.event.*;

public class ChatServer extends JFrame implements ActionListener{
	public static ServerSocket server;
	public static Socket soc;
	public static JPanel jpanel;
	public static JButton jbutton;
	public static JTextField jtextfield;
	public static JTextArea jtextarea;

	public ChatServer()throws Throwable{
		jpanel = new JPanel();
		jbutton = new JButton("click");
		jtextfield = new JTextField();
		jtextarea = new JTextArea();
		
		this.setVisible(true);
		this.setSize(500,500);
		this.setTitle("server");
		
		jpanel.setLayout(null);
		jtextarea.setBounds(20,20,420,360);
		jtextfield.setBounds(20,460,300,30);
		jbutton.setBounds(360,460,70,30);
		
		this.add(jpanel);
		jpanel.add(jtextarea);
		jpanel.add(jtextfield);
		jpanel.add(jbutton);

		jbutton.addActionListener(this);				
		server = new ServerSocket(2999);
		soc = server.accept();
		jtextarea.setText("Found Client");
		while(true){
			BufferedReader buffer = new BufferedReader(new InputStreamReader(soc.getInputStream()));	
			String temp = buffer.readLine();
			jtextarea.setText(jtextarea.getText()+"\nclient:"+temp);
				
		}
	}

	public void actionPerformed(ActionEvent e){
		if((e.getSource()==jbutton) && (jtextfield.getText()!="")){
//			BufferedReader buffer = new BufferedReader(new InputStreamReader(soc.getInputStream));		
			try{			
				PrintStream ps = new PrintStream(soc.getOutputStream());
				ps.println(jtextfield.getText());
				jtextarea.setText(jtextarea.getText()+"\nme:"+jtextfield.getText());				
			}catch(Exception e1){}
			jtextfield.setText("");		
		}
	}

	public static void main(String[] args)throws Throwable{
		new ChatServer();
	}
}
