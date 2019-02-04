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
	
	
	private JTextArea textArea;
	
	private AbstractAction act1;
	private AbstractAction act2;
	private AbstractAction act3;
	

	public MainFrame(){
		act1 = new AbstractAction("B-1") {
			private static final long serialVersionUID = 1L;

			@Override
			public void actionPerformed(ActionEvent e) {
				textArea.append("Salut du boutton1 \n");
			}
		};
		
		act1.putValue(Action.MNEMONIC_KEY, new Integer(KeyEvent.VK_A));
		
		act2 = new AbstractAction("B-2") {
			private static final long serialVersionUID = 1L;

			@Override
			public void actionPerformed(ActionEvent e) {
				textArea.append("Salut du boutton2 \n");
			}
		};
		
		act3 = new AbstractAction("B-3") {
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
		this.textArea = new JTextArea(20,20);
		
		JScrollPane scrollPane = new JScrollPane(this.textArea);
		scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
		scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
		
		JPanel panel = new JPanel();
		
		panel.add(new JButton(act1));
		panel.add(new JButton(act2));
		panel.add(new JButton(act3));
		
		
		add(scrollPane, BorderLayout.CENTER);
		add(panel, BorderLayout.SOUTH);
	}
	
	private void initMenuBar() {
		JMenuBar bar = new JMenuBar();
		JMenu menu = new JMenu("Menu 1");
		
		menu.add(new JMenuItem(act1));
		menu.add(new JMenuItem(act2));
		menu.add(new JMenuItem(act3));
		bar.add(menu);
		setJMenuBar(bar);
	}
	
	private void initToolBar() {
		JToolBar bar = new JToolBar();

		bar.add(new JMenuItem(act1));
		bar.add(new JMenuItem(act2));
		bar.add(new JMenuItem(act3));
		
		add(bar, BorderLayout.NORTH);
	}

}
