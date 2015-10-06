TITLE Project 1     (program1.asm)

; Author:Luke Brewbaker
; Course / Project ID   CS 271/project 1              Date: 9/29/15
; Description: Doing simple arithmetic calculations

INCLUDE Irvine32.inc


.data

intro_1		BYTE	"Hi, I am Luke.  This program will do simple arithmetic. ",0	
instruction BYTE	"Please enter 2 numbers into the console that you would like to use. ",0
instruct1	BYTE	"First number: ",0
instruct2	BYTE	"Second number: ",0
usernumone	DWORD	?
usernumtwo	DWORD	?
checkzero	BYTE	"You cannot divide by 0!", 0
checknums	BYTE	"Please make the second number smaller than the first.", 0
addresults	BYTE	"The addition results are: ",0
subresults	BYTE	"The subtraction results are: ",0
prodresults	BYTE	"The product results are: ",0
divresults	BYTE	"The division results are: ",0
remresults	BYTE	"The remainder is: ",0
sum			DWORD	?
subtract	DWORD	?
product		DWORD	?
divider		DWORD	?
remainder	DWORD	?
continue	BYTE	"Would you like to try different numbers? (0 no, 1 yes)", 0
contanswer	DWORD	?
goodbye		BYTE	"So long and Goodbye! ",0 

.code
main PROC

;introduce myself, tell them what we're doing.
	mov	edx, OFFSET intro_1
	call WriteString
	call Crlf

;display instructions for the user
	mov	edx, OFFSET instruction
	call WriteString
	call Crlf

;collect first value from user
	start:							;flags the program to restart here if the user wishes to continue
		mov edx, OFFSET instruct1
		call WriteString
		call ReadInt
		mov usernumone, eax

;collect 2nd value

collectnumtwo:
	mov edx, OFFSET instruct2
	call WriteString
	call ReadInt
	mov usernumtwo, eax

;check to make sure 2nd value isn't 0
	cmp eax, 0
	jnz istwosmaller		;jumps to second check if 2nd value is not 0
	mov	edx, OFFSET checkzero
	call WriteSTring
	call CrLf
	jmp collectnumtwo		;jumps back to collect 2nd number


;check if number 2 is smaller
istwosmaller:
	mov	eax, usernumone
	mov	ebx, usernumtwo

	cmp eax, ebx
	jg maths				;jumps to maths if 1 is greater than 2
	mov	edx, OFFSET checknums
	call WriteString
	call CrLf
	jmp collectnumtwo		;jumps back to collect 2nd number again


;calculate values
maths:
	;multiplication
		mov eax, usernumone
		mov ebx, usernumtwo
		mul eax
		mov product, eax

	;addition
		mov eax, usernumone
		add eax, usernumtwo
		mov sum, eax

	;subtraction
		mov eax, usernumone
		sub eax, usernumtwo
		mov subtract, eax

	;divider
		mov eax, usernumone
		cdq
		mov ebx, usernumtwo
		div ebx
		mov divider, eax
		mov remainder, edx


;display results

	;multiplication
		mov edx, OFFSET prodresults
		call WriteString
		mov eax, product
		call WriteDec
		call CrLf

	;sum
		mov edx, OFFSET addresults
		call WriteString
		mov eax, sum
		call WriteDec
		call CrLf

	;subtract
		mov edx, OFFSET subresults
		call WriteString
		mov eax, subtract
		call WriteDec
		call CrLf

	;divider
		mov edx, OFFSET divresults
		call WriteString
		mov eax, divider
		call WriteDec
		Call CrLf
		mov edx, OFFSET remresults
		call WriteString
		mov eax, remainder
		call WriteDec
		call CrLf

;continue the program
	mov		edx, OFFSET continue
	call	WriteString
	call	ReadInt
	mov		eax, contanswer
	jnz		start					;jump back to the start

;good bye
	mov edx, OFFSET goodbye
	call WriteString
	call CrLf




	exit		; exit to operating system
main ENDP

; (insert additional procedures here)

END main