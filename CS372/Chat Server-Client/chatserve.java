/****************************************************************************************
Author: Luke Brewbaker
Date: 4/24/16
Modified:4/29/16
File: chatserve.java
OSU CS372

Overview:
This is the server side of the chat client.  This program will accept a port number greater than 1024 and creates a TCP socket. 
The socket will listen and accept connections from the client (chatclient.py).  Once a connection is made, it can be terminated with /quit
or with a SIGINT command (Ctrl + C).

Additional sources: 
https://docs.oracle.com/javase/tutorial/essential/io/cl.html
https://docs.oracle.com/javase/tutorial/networking/sockets/clientServer.html
http://stackoverflow.com/questions/4067809/how-can-i-find-whitespace-space-in-a-string
http://www.dreamincode.net/forums/topic/259777-a-simple-chat-program-with-clientserver-gui-optional/

  
****************************************************************************************/
import java.io.IOException;
import java.io.Console;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.util.Scanner;
import java.net.*;

public class chatserve {
  public static void main(String[] args) throws IOException {

    // Check for the correct number of arguments (1)
    if (args.length != 1) {
      System.err.println(" usage: { java chatserve <port_number> }");
      System.exit(1);
    }

    // Gets Port num from command line as INT and creates a new socket connection
    int serverPort = Integer.parseInt(args[0]);
    ServerSocket serverSocket = new ServerSocket(serverPort);

    // Inform chatserve user that Server is now listening for a connection
    System.out.println("\nWelcome to the Chat Server.");
    System.out.println("Port " + serverPort + ": chatserve now listening for connection.\n");

    // Get the users handle from the command line and performs input verification.
    Console c = System.console();
    String chatHandle = c.readLine("Enter a chatserve handle: ");
    while ((chatHandle.length() > 10) || (containsWhiteSpace(chatHandle))) {
      System.out.println("\Error: 10 character maximum and no whitespace allowed. Try again.");
      chatHandle = c.readLine("Enter a chatserve handle: ");
    }

    // Set header to chat handle user enterred
    String messageHeader = chatHandle + "> ";

    // Infinite Loop to wait for chatclient.py.  ends if SIGNIT recieved.
    while (true) {

      // If a connection is made:
      Socket clientSocket = serverSocket.accept();
      System.out.println("\nConnection with client established.");
      System.out.println("Use \\quit or CTRL+C to end connection.\n");

      // Begin I/O stream and set up chat variables
      BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
      PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
      String cQuit = "\\quit";
      String sQuit = "\\quit";
      String message = " ";
      String replyMessage;

      // Scanner to get messages from server and send to client.
      Scanner serverMessage = new Scanner(System.in);

      // Infinite loop until Client or Server uses \quit command
      while ((replyMessage = in.readLine()) != null) {
	  
        // If \quit command sent from Client, end connection with this client
        if (replyMessage.equals(cQuit)) {
          System.out.println("Connection ended by client.");
          System.out.println("Port " + serverPort + ": server now listening for new connection.");
          out.close();
          in.close();
          clientSocket.close();
          break;
        }

        // Print message from client to server.
        System.out.println(replyMessage);

        // Prompt chatserve user to enter a reply
        System.out.print(messageHeader); // chatserve handle
        message = serverMessage.nextLine(); // get server message

        // Limit message lengths to 500 characters.
        while ((message.length()) > 500) {
          System.out.println("\nError: Messages must be 500 characters or less. Try again.\n");
          System.out.print(messageHeader);
          message = serverMessage.nextLine();
        }

        // send message from server to client 
        out.println(messageHeader + message);

        // If \quit command sent, end connection with this client
        if (message.equals(sQuit)) {
          System.out.println("Connection ended by server.");
          System.out.println("Port " + serverPort + ": server now listening for new connection.");
          out.close();
          in.close();
          clientSocket.close();
          break;
        }
     }
    }
  }

  
  // function to check for white space in a String.  Returns True if there is any white space in that string.
 public static boolean containsWhiteSpace(final String testCode) {
    if (testCode != null) {
      // loop through each character in the String and tests each for white space.
      for (int i = 0; i < testCode.length(); i++) {
		  // if found, return true.
        if (Character.isWhitespace(testCode.charAt(i))) {
          return true;
        }
      }
    }
	// else return false
    return false;
  }
}
