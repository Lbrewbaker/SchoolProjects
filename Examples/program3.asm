TITLE Program Template			(program3.asm)

; Program Description:
; Author: Luke Brewbaker
; Date Created: 10/27/15
; Last Modification Date: 10/27/15

INCLUDE Irvine32.inc

LOWERLIMIT = -100
UPPERLIMIT = -1

.data

usersName	BYTE	33 DUP(0)
usersNumber	SDWORD	?
intro		BYTE	"Program 3, Integer Accumulator by Luke Brewbaker", 0
info		BYTE	"Today we're going to calculate and display average of any number of numbers of your choosing as a floating point number, or rounded", 0
prompt1		BYTE	"What is your name? ", 0
prompt2		BYTE	"Greetings, ", 0
prompt3		BYTE	"Please enter a number between -100 and -1 : ", 0
prompt4		BYTE	"Entere a non-negative number to see the results. ", 0
prompt5		BYTE	"Enter a number: ", 0
prompt6		BYTE	"The sum of your numbers is ", 0
prompt7		BYTE	"The rounded average is ", 0
prompt8		BYTE	"The float average is ", 0
toolow		BYTE	"Number too low, please try again ", 0
invalid2	BYTE	"Please enter a number ", 0
goodbye		BYTE	"Thanks for playing!", 0
goodbye1	BYTE	"So long, ", 0
numcount	SDWORD	?
sumcount	SDWORD	?	
average		SDWORD	?
floatnumcount	REAL8	?
floatsumcount	REAL8	?
floataverage	REAL4	?


.code
main PROC


;Introductions
	mov		edx, OFFSET intro
	call	WriteString
	call	CrLf

;Get users name
	mov		edx, OFFSET prompt1		;display the message to get users name
	call	WriteString
	mov		edx, OFFSET usersName
	mov		ecx, 32
	call	ReadString				;receive the input from the console
	mov		edx, OFFSET prompt2
	call	WriteString
	mov		edx, OFFSET usersName	;display the greeting message with the players name
	call	WriteString
	call	CrLf

;Displays instructions to user
	mov 	edx, OFFSET prompt3
	call	WriteString
	call	CrLf
	call	CrLf	

;get the users numbers and input
	mov		numcount, 1 	;set the number count initially to 1, will increment with each additional pass
getNumber:
	mov		edx, OFFSET prompt5
	call	WriteString
	call	ReadInt
	cmp		eax, LOWERLIMIT
	jl		numLow;
	cmp		eax, UPPERLIMIT
	jg		results
	call	calcAverage			;jumps to calculate average if numbers are within range

numLow:
	;displays an error message if the number is too low and loops back to the get number section
	mov		edx, OFFSET toolow
	call	WriteString
	call	CrLf
	call	getNumber

calcAverage:
	;this is called each time to adjust the average based on how many numbers have been entered so far
	inc		numcount
	add		sumcount, eax
	dec		numcount
	mov		eax, sumcount
	cdq
	mov		ebx, numcount
	idiv	ebx
	mov		average, eax
	fild	numcount			
	fst		floatnumcount
	cdq

	fild	sumcount			
	fst		floatsumcount
	fdiv	ST(0), ST(1)		
	fst		floataverage		
	inc		numcount
	call	getNumber


results:
;displays the results

	;check if the user only enterred 1 number
	mov		numcount, eax
	cmp		numcount, 1
	jle		getNumber

	;else print the results
	call	CrLf
	mov		edx, OFFSET prompt6
	call	WriteString
	mov		eax, sumcount
	call	WriteInt
	call	CrLf
	mov		edx, OFFSET prompt7
	call	WriteString
	mov		eax, average
	call	WriteInt
	call	CrLf
	mov		edx, OFFSET prompt8
	call	WriteString
	call	CrLf
	mov		eax, floataverage
	call	WriteFloat
	call	CrLf
	call	CrLf


	;displays the goodbye message
	mov		edx, OFFSET goodbye
	call	WriteString
	call	CrLf
	mov		edx, OFFSET goodbye1
	call	WriteString
	mov		edx, OFFSET usersName
	call	WriteString
	call	CrLf

	exit		; exit to operating system

main ENDP
; (insert additional procedures here)

END main