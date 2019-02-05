//
// Client Java pour communiquer avec le Serveur C++ 
// eric lecolinet - telecom paristech - 2015
//

import java.io.*;
import java.net.*;

import interfaces.Printer;

public class Client
{
	private static final long serialVersionUID = 1L;
	static final String DEFAULT_HOST = "localhost";
	static final int DEFAULT_PORT = 3331;

	private Socket sock;
	private Printer printer;
	private BufferedReader input;
	private BufferedWriter output;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	///
	/// Crée le client. 
	/// A fournir, un printer pour afficher les messages du client.
	/// Renvoie le client (ou null en cas d'echec)
	///
	public static Client connect(Printer printer) {
		return connect(printer, DEFAULT_HOST, DEFAULT_PORT);
	}


	public static Client connect(Printer printer, String host, int port) {
		Client client = null;

		try {
			client = new Client(printer, host, port);
		}
		catch (Exception e) {
			if (printer != null)
				printer.print("Client: Couldn't connect to "+host+":"+port);
			else
				System.err.println("Client: Couldn't connect to "+host+":"+port);
			return null;
		}

		if (printer != null)
			printer.print("Client connected to "+host+":"+port);
		else
			System.err.println("Client connected to "+host+":"+port);
		return client;
	}
	
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	///
	/// Initialise la connexion.
	/// Renvoie une exception en cas d'erreur.
	///
	public Client(Printer printer, String host, int port) throws UnknownHostException, IOException {
		this.printer = printer;
		try {
			sock = new java.net.Socket(host, port);
		}
		catch (java.net.UnknownHostException e) {
			print("Client: Couldn't find host "+host+":"+port);
			throw e;
		}
		catch (java.io.IOException e) {
			print("Client: Couldn't reach host "+host+":"+port);
			throw e;
		}

		try {
			input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
			output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
		}
		catch (java.io.IOException e) {
			print("Client: Couldn't open input or output streams");
			throw e;
		}
	}

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	///
	/// Envoie une requete au server et retourne sa reponse.
	/// Noter que la methode bloque si le serveur ne repond pas.
	///
	public String send(String request) {
		// Envoyer la requete au serveur
		try {
			request += "\n";  // ajouter le separateur de lignes
			output.write(request, 0, request.length());
			output.flush();
		}
		catch (java.io.IOException e) {
			print("Client: Couldn't send message: " + e);
			return null;
		}	/**
		 * 
		 */

		// Recuperer le resultat envoye par le serveur
		try {
			return input.readLine();
		}
		catch (java.io.IOException e) {
			print("Client: Couldn't receive message: " + e);
			return null;
		}
	}

	///
	/// Affiche les messages du client sur le printer
	/// Ou sur la sortie standart si le printer n'est pas defini
	///
	public void print(String message) {
		if (printer != null)
			printer.print(message);
		else
			System.err.println(message);

	}
}

