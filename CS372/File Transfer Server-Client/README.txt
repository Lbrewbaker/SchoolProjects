Program 2 Instructions:


Server instructions:

1. Upload files to flip.  Upload file and server in separate locations.  Makefile has to be in file with ftserver.cpp
2. Compile the server with: "make all" command.
3. Start server with "./server <port number>"

Server should be running on the port you specified.  You will see this message: 
	flip1 ~/cs372/project2 145% ./server 20005
	Server open on 20005


Client instructions:

1. Ensure client is in separate directory than server.
2. Start up a new instance of putty.  
3. By default, my client logs into flip1, which is where the server is running.  You will have to ssh to flip3 with "ssh flip3.oregonstate.edu" and re-enter your credentials.
4. Navigate to client directory
5. Client usage as follows: python ftclient.py <server host> <server port> <commands: -l | -g filename <data port>

To get a list of the server directory:
	python ftclient.py flip1 20005 -l 20004

Client should print the contents:
	Receiving directory structure from flip1:20004
	ftclient.py
	ftserver.cpp
	server
	client
	makefile
	javatest.java
	test.pdf

Server should respond:
	Connection from flip2.engr.oregonstate.edu
	List directory requested on port 20004
	Sending directory contents to flip1:20004

	
To transfer a file from the server to the client:
	python ftclient.py flip1 20005 -g test.pdf 20004
	
Client should say:
	Receiving "test.pdf" from flip1:20004
	File transfer complete

Server should say:
	Connection from flip2.engr.oregonstate.edu
	File "test.pdf" requested on port 20004
	Sending "test.pdf" to flip1:20004
	
	
	
Common errors:
1. When running client, and server is not open you will see:
	"Error: Could not open socket on <port number>
Fix: Start server on <port number>

2. 
