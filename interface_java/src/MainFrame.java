import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.Icon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JToolBar;

public class MainFrame extends JFrame {

	private static final long serialVersionUID = 1L;
	
	public static void main(String argv[]) {
		JFrame frame = new MainFrame();
		
	}
	
	private Client client;
	
	private TextArea textArea;
	
	private AbstractAction connectAction;
	private AbstractAction act2;
	private AbstractAction act3;
	

	public MainFrame(Client client){
		this.client = client;
		
		connectAction = new AbstractAction("Connect") {
			private static final long serialVersionUID = 1L;

			@Override
			public void actionPerformed(ActionEvent e) {
				client.connect(textArea);
			}
		};
		
		
		
		act2 = new AbstractAction("B-2") {
			private static final long serialVersionUID = 1L;

			@Override
			public void actionPerformed(ActionEvent e) {
				textArea.append("Salut du boutton2 \n");
			}
		};
		
		act3 = new AbstractAction("Quit") {
			private static final long serialVersionUID = 1L;

			@Override
			public void actionPerformed(ActionEvent e) {
				dispose();
			}
		};

		initPanel();
		initMenuBar();
		initToolBar();
		
		this.setTitle("Medias");
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		this.pack();
		this.setVisible(true);
	}
	
	private void initPanel() {
		this.textArea = new TextArea(20,20);
		
		JScrollPane scrollPane = new JScrollPane(this.textArea);
		scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
		scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
		
		JPanel panel = new JPanel();
		
		panel.add(new JButton(connectAction));
		panel.add(new JButton(act2));
		panel.add(new JButton(act3));
		
		
		add(scrollPane, BorderLayout.CENTER);
		add(panel, BorderLayout.SOUTH);
	}
	
	private void initMenuBar() {
		JMenuBar bar = new JMenuBar();
		JMenu menu = new JMenu("Connection :");
		
		menu.add(new JMenuItem(connectAction));
		menu.add(new JMenuItem(act2));
		menu.add(new JMenuItem(act3));
		bar.add(menu);
		setJMenuBar(bar);
	}
	
	private void initToolBar() {
		JToolBar bar = new JToolBar();

		bar.add(new JMenuItem(connectAction));
		bar.add(new JMenuItem(act2));
		bar.add(new JMenuItem(act3));
		
		add(bar, BorderLayout.NORTH);
	}

}
