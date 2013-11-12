import java.io.*;
import java.net.*;
class TCPServer {
public static void main(String argv[]) throws Exception {
	String clientSentence;
	String capitalizedSentence;

	//create a welcome socket, and binds it to port 5000
	ServerSocket welcomeSocket = new ServerSocket (5000);
	while(true) {
		//accept connection request from client
		Socket connectionSocket = welcomeSocket.accept(); 
		//accept() method creates new socket for client.
		//new client-specific socket is called "connection socket"

		//Create reader object to read and write to the socket
		BufferedReader inFromClient = //puts input stream into buffered reader
			new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));

		//Declare output stream to carry capitalized sentence.
		DataOutputStream outToClient = 
			new DataOutputStream(connectionSocket.getOutputStream());

		//Take buffered input stream store in clientSentence
		clientSentence = inFromClient.readLine();

		//capitalize sentence and send back to client.
		capitalizedSentence = clientSentence.toUpperCase()+'\n'; 
		outToClient.writeBytes(capitalizedSentence);
	} // while
} // main()
} // class TCPServer
