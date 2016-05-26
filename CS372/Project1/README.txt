Author: Luke Brewbaker
Modified: 29 April 2016 
Program Description: TCP chat client/server
File: README.txt
-----------------------------------------------

To Compile:
	Upload all files to the flip.engr.oregonstate.edu server.
		Files include:
			chatserve.jara
			chatclient.py
			makefile
	Once uploaded run:
		make all
		
	Confirm "chatserve.class" was created.
	
-----------------------------------------------

To Start Server:
	In the directory of chatserve.java, enter:
		java chatserve <port number>
	Note: Port must be greater than 1024.
	Enter a chat handle.
	Wait for connecting client.
	
To Start Client:
	In the director of chatclient.py, enter:
		python chatclient.py <host server> <host port number>
	The host server will be either flip1, flip2, or flip 3.  Port is the port the server is running.
	If connection succeeds, enter chat handle.
	If connection fails, exit program.

	
To Clean files:
	enter make clean.
	

-----------------------------------------------
	
Sample:
    Host:
          make all
          java chatserve 1024
		  Message Displayed: 
			"Welcome to the Chat Server
			Port: 1025: chatserve now listening for connection
			
			Enter a chat handle: Bill "
    Client:
          python chatclient.py flip1 1024
		  Message Display:
			" Welcome to Chat Server of Awesomeness.
			Connection with chatserve established.
			Use \quit or CTRL +C to end connection.
			
			Enter a chat handle: Jill"
			
	At this point, entering a chat handle will allow you to chat.  Messages get sent 1 at a time.  You must wait for a reply before another message is sent.  there is a 500 character ma, and no white space allowed in chat names.
		
	
