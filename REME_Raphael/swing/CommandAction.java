import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;
import javax.swing.JFrame;
import javax.swing.JOptionPane;


// Class use for command action.
// Display a Dialog to get the argument of the command.
// And then send the command to the server threw the client.
public class CommandAction extends AbstractAction {

	private static final long serialVersionUID = 1L;

	private MainFrame frame;
	private String command;

	public CommandAction(MainFrame frame, String command, String title) {
		super(title);
		this.command = command;
		this.frame = frame;
	}
	@Override
	public void actionPerformed(ActionEvent arg0) {
		String s = (String)JOptionPane.showInputDialog(
                frame, "Which one ?", "Choose",
                JOptionPane.PLAIN_MESSAGE, null, null, null);

		if (s == null) {
			return;
		}

		String com = this.command + " " + s;
		Printer printer = frame.getPrinter();
		Client client = frame.getClient();

		printer.print(">>" + com);
		String response = null;

		if (client != null)
			response = client.send(com);
		else {
			printer.print("Please connect to server.");
			return;
		}
		printer.print(response);
	}

}
