import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class MainFrame extends JFrame {

	private static final long serialVersionUID = 1L;
	
	public static void main(String argv[]) {
		JFrame frame = new MainFrame();
		
	}
	
	
	private JTextArea textArea;
	private JButton button1;
	private JButton button2;
	private JButton button3;

	public MainFrame(){
		
		//this.setIconImage();
		initPanel();
		initMenuBar();
		
	
		//menuBar = new MenuBar(this);
		
		
		
		//this.setJMenuBar(menuBar);
		//this.setContentPane(contentPanel);
		
		this.setTitle("Medias");
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		this.pack();
		this.setVisible(true);
	}
	
	private void initPanel() {
		this.textArea = new JTextArea(20,20);
		
		JScrollPane scrollPane = new JScrollPane(this.textArea);
		scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
		scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
		
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
		
		
		add(scrollPane, BorderLayout.CENTER);
		add(panel, BorderLayout.SOUTH);
	}
	
	private void initMenuBar() {
		JMenuBar bar = new JMenuBar();
		JMenu menu = new JMenu("Menu 1");
		JMenuItem item = new JMenuItem("Item 1");
		
		menu.add(item);
		bar.add(menu);
		setJMenuBar(bar);
		
		
	}

}
