import java.io.*;
import java.net.*;
class TCPClient {

public static void main(String argv[]) throws Exception
{
	String sentence;
	String modifiedSentence;

	//Create a reader for reading from keyboard
	BufferedReader inFromUser = new BufferedReader(
		new InputStreamReader(System.in));

	//Create a socket by specifying destination IP and port 5000
	Socket clientSocket = new Socket("storm.cis.fordham.edu",5000);

	//Create an output stream for the socket, used to write to the socket
	DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());

	//Create a bufferedReader to read from the socket 
	BufferedReader inFromServer = // will receive modifiedSentence
		new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

	//Read a line from keyboard
	sentence = inFromUser.readLine();
	//write the line (and a newline char) to the socket 
	outToServer.writeBytes(sentence + "\n");

	//read from the socket
	modifiedSentence = inFromServer.readLine();

	//display the message received ... 
	System.out.println("FROM SERVER: " + modifiedSentence);

	//close the socket
	clientSocket.close();
}
}
