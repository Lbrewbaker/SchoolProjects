TITLE Program 2		(program2.asm)

; Program Description: Fibonacci to the nth power program
; Author: Luke Brewbaker	
; Date Created: 10/6/15
; Last Modification Date:  10/6/15

INCLUDE Irvine32.inc


TOPLIMIT = 46



.data

playersname		DWORD	30 DUP(0)
intro1			BYTE	"Welcome to the Fantastic Fibonacci", 0
intro2			BYTE	"My name is Luke Brewbaker, i'll be your narator today", 0
playername		BYTE	"What's your name? ", 0
greetings		BYTE	"Greetings, ",0
fibnum1			BYTE	"How many Fibonacci numbers would you like to see?", 0
fibnum2			BYTE	"Please enter a number between 1 and 46. ", 0
fibnum3			BYTE	"How many terms would you like to see? ", 0
toobig			BYTE	"Number is too high. Please only use 1-46. ", 0
toosmall		BYTE	"Number is too small.  Please only use 1-46. ", 46
space			BYTE	"     ", 0
goodbye1		BYTE	"Looks good, eh? ",0
goodbye2		BYTE	"So long ",0
goodbye3		BYTE	"!",0
playernum		DWORD	?
linecount		DWORD	1
fib1			DWORD	?
fib2			DWORD	1

.code
main PROC
	
	;Introductions
		mov edx, OFFSET intro1
		call WriteString
		call CrLf
		mov edx, OFFSET intro2
		call WriteString
		Call CrLf

	;Get player name
		mov edx, OFFSET playername
		call WriteString
		mov edx, OFFSET playersname
		mov ecx, 32
		call ReadString

	;Greet player
		mov edx, OFFSET greetings
		call WriteString
		mov edx, OFFSET playersname
		call WriteString
		call CrLf
	
	;Instructions
		mov edx, OFFSET fibnum1
		call WriteString
		call CrLf
		mov edx, OFFSET	fibnum2
		call WriteString
		call CrLf
	
	;Get player's numbers
	getnumber:
		mov eax, 0
		mov edx, OFFSET fibnum3
		call WriteString
		call ReadInt
		mov  playernum, eax
	
	;Check valid number

	checktop:					;checks top number first
		mov eax, playernum
		cmp eax, TOPLIMIT
		jg overlimit			;jump to overlimit loop
		jle checkbot			;jump to check bottom if less than 46

	checkbot:
		mov eax, playernum
		cmp eax, 1
		jg goodnum				;jump to the start of the sequence if number is > 1
		jl underlimit			;jump to underlimit loop if < 1

	overlimit:
		mov edx, OFFSET toobig
		call WriteString
		call CrLf
		jmp getnumber

	underlimit:
		mov edx, OFFSET toosmall
		call WriteString
		call CrLf
		jmp getnumber			;redo the get number loop
		

	;calculate and display the fib sequence
	goodnum:
		call CrLf				;insterted a break line here for better visualization in the console
		mov	ecx, playernum
		mov	eax, 0   					
		mov	ebx, 1    	 				
		mov	fib1, eax				
		mov	fib2, ebx


	calcfib:
		cmp ecx, 0
		je donefib
		mov	eax, fib1				
		mov	ebx, fib2				
		mov	edx, eax						
		add	edx, fib2				
		mov	eax, ebx						
		mov	ebx, edx						
		mov	fib1, eax				
		mov	fib2, ebx
		cmp	ecx, 0						;check if there are remainign terms to be calculated
		jg display
		jle donefib		
			
	;display the lines
	display:
		mov edx, OFFSET fib2
		call WriteInt
		mov edx, OFFSET space
		call WriteString
		mov ebx, linecount
		cmp ebx, 5				;compares to display limit of 5
		je newline				;jumps to nextline to print CrLF (newline)
		inc ebx					;increase line counter
		mov linecount, ebx
		loop calcfib			;if this is not here, the counter doesn't get decremented and program continues
		jmp calcfib				;jump back to start and calculate a new fibonacci number
	
	newline:
		call CrLf
		mov linecount, 1		;set line item counter back to 1
		loop calcfib			
		jmp calcfib

	;Good-bye 
	donefib:
		call CrLf
		mov edx, OFFSET goodbye1
		call WriteString
		call CrLf
		mov edx, OFFSET goodbye2
		call WriteString
		mov edx, OFFSET playersname
		call WriteString
		mov edx, OFFSET goodbye3
		call WriteString
		call CrLf


	exit		; exit to operating system
main ENDP

; (insert additional procedures here)

END main