import java.io.*;
import java.net.*;
class TCPServer {
public static void main(String argv[]) throws Exception
{
	String clientSentence;
	String capitalizedSentence;

	//create a welcome socket, and binds it to port 5000
	ServerSocket welcomeSocket = new ServerSocket (5000);
	while(true) {
		//accept connection request from client
		Socket connectionSocket = welcomeSocket.accept();

		//Create reader and output object to read and write to the socket
		BufferedReader inFromClient =
			new BufferedReader(new InputStreamReader(
				connectionSocket.getInputStream()));

		DataOutputStream outToClient =
			new DataOutputStream(
				connectionSocket.getOutputStream());

		//Read a line from the socket 
		clientSentence = inFromClient.readLine();

		//write the captilized sentence back to client 
		capitalizedSentence =
clientSentence.toUpperCase() + '\n'; outToClient.writeBytes(capitalizedSentence);
	}
}
}
