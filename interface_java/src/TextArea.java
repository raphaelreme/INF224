import javax.swing.JTextArea;

import interfaces.Printer;

public class TextArea extends JTextArea implements Printer {

	private static final long serialVersionUID = 1L;

	public TextArea(int i, int j) {
		super(i,j);
	}

	@Override
	public void print(String message) {
		append(message + "\n");
	}

}
