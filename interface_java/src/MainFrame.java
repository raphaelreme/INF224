import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;

public class MainFrame extends JFrame {

	private static final long serialVersionUID = 1L;
	
	private JTextArea textArea;
	private JButton button1;
	private JButton button2;
	private JButton button3;

	public MainFrame(){
		this.setTitle("Medias");
		//this.setIconImage();
		//this.setSize(700,700);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		
		//contentPanel = new Panel(this);
		//menuBar = new MenuBar(this);
		
		this.textArea = new JTextArea(20,20);
		
		JPanel panel = new JPanel();
		button1 = new JButton("1");
		button2 = new JButton("2");
		button3 = new JButton("Quit");
		
		button1.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				textArea.append("Salut du boutton1 \n");
			}
		});
		
		button2.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				textArea.append("Salut du boutton2 \n");
			}
		});
		
		button3.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				MainFrame.this.dispose();			
			}
		});
		
		
		panel.add(button1);
		panel.add(button2);
		panel.add(button3);
		
		
		add(this.textArea, BorderLayout.CENTER);
		add(panel, BorderLayout.SOUTH);
		
		//this.setJMenuBar(menuBar);
		//this.setContentPane(contentPanel);
		this.pack();
		this.setVisible(true);
		
		
	}
	
	public static void main(String argv[]) {
		JFrame frame = new MainFrame();
		
	}
}
