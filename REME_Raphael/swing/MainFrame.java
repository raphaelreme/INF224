import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.InputMethodEvent;
import java.awt.event.InputMethodListener;
import java.awt.event.KeyEvent;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.Icon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JToolBar;
import javax.swing.event.CaretEvent;
import javax.swing.event.CaretListener;



/*
 * Main frame of the application.
 * Display the server answers and allow the user to send requests.
 */
public class MainFrame extends JFrame {

	private static final long serialVersionUID = 1L;

	public static void main(String argv[]) {
		JFrame frame = new MainFrame();

	}

	private Client client;

	private TextArea textArea;

	private AbstractAction connectAction;
	private AbstractAction findm;
	private AbstractAction findg;
	private AbstractAction play;
	private AbstractAction quit;

	public MainFrame(){
		client = null;

		connectAction = new AbstractAction("Connect") {
			private static final long serialVersionUID = 1L;

			@Override
			public void actionPerformed(ActionEvent e) {
				client = Client.connect(textArea);
			}
		};
		//Rajouter une commande generale ?
		findm = new CommandAction(this, "findm", "Find a media");

		findg = new CommandAction(this, "findg", "Find a group");

		play = new CommandAction(this, "play", "Play media");

		quit = new AbstractAction("Quit") {
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
		textArea = new TextArea(20,20);
		textArea.setEditable(false);

		JScrollPane scrollPane = new JScrollPane(this.textArea);
		scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
		scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);

		JPanel panel = new JPanel();

		panel.add(new JButton(connectAction));
		panel.add(new JButton(findm));
		panel.add(new JButton(findg));
		panel.add(new JButton(play));
		panel.add(new JButton(quit));


		add(scrollPane, BorderLayout.CENTER);
		add(panel, BorderLayout.SOUTH);
	}

	private void initMenuBar() {
		JMenuBar bar = new JMenuBar();

		JMenu connection = new JMenu("Connection");
		connection.add(new JMenuItem(connectAction));
		connection.add(new JMenuItem(quit));


		JMenu media = new JMenu("Media");
		media.add(new JMenuItem(findm));
		media.add(new JMenuItem(play));

		JMenu group = new JMenu("Group");
		group.add(new JMenuItem(findg));


		bar.add(connection);
		bar.add(media);
		bar.add(group);

		setJMenuBar(bar);
	}

	private void initToolBar() {
		JToolBar bar = new JToolBar();

		bar.add(new JMenuItem(connectAction));
		bar.add(new JMenuItem(findm));
		bar.add(new JMenuItem(findg));
		bar.add(new JMenuItem(play));

		add(bar, BorderLayout.NORTH);
	}

	public Client getClient() {
		return client;
	}

	public Printer getPrinter() {
		return textArea;
	}

}
