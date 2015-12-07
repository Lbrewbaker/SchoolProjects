TITLE Program 4		(program4.asm)

; Program Description:
; Author: Luke Brewbaker
; Date Created:15 Oct 15
; Last Modification Date: 8 Nov 15

INCLUDE Irvine32.inc

;Contants declaration
LOWERLIMIT = 1
UPPERLIMIT = 400
LINEDISPLAY = 10

.data

intro1		BYTE		"Componsite Numbers.  Written by Luke Brewbaker",0
intro2		BYTE		"Please specify the number of composite numbers you'd like to see (max of 400)",0
prompt		BYTE		"Please enter a number between 1 and 400",0
invalid		BYTE		"Your number is not in the specified range",0
continue	BYTE		"Continue? (0 for no, 1 for yes)", 0
bye1		BYTE		"Numbers certified by Luke Brwbaker",0
bye2		BYTE		"Aloha",0
colon		BYTE		":",0
input		DWORD		?	
space		BYTE		" ",0
userNum		DWORD		?
counter		DWORD		?
temp		DWORD		?
checkNum	DWORD		2
testNum		DWORD		4



.code

;introduces the program and provides instructions
intro PROC

mov		edx, OFFSET intro1
call	WriteString
call	CrLf
mov		edx, OFFSET intro2
call	WriteString
call	CrLf
ret

intro ENDP



;gets users number for the program
getNumber PROC

mov		edx, OFFSET prompt
call	WriteString
mov		edx, OFFSET colon
call	WriteString
mov		edx, OFFSET space
call	WriteString
call	ReadInt
mov		usernum, eax
call	CrLf
jmp		checknumbers

getNumber ENDP



; checks to make sure input is within valid range
checkNumbers PROC

cmp		eax, LOWERLIMIT
jl		notValid
cmp		eax, UPPERLIMIT
jg		notValid
ret		;number should be valid if it gets to this point

;invalid number prompt, returns to get a new number
notValid:
mov		edx, OFFSET invalid
call	WriteString
call	CrLf
jmp getNumber

checkNumbers ENDP



;calculates the composite numbers
checkComp PROC

; validates the number is a composite number

testNumbers:
mov		ecx, testNum
xor		edx, edx
mov		eax, testNum
mov		ebx, checkNum
div		ebx
cmp		edx, 0
je		compNumber			;if edx is 0, the number is composite and program jumps

;if greater than 0, it is not a composite number and performs the following operations
inc		checkNum
mov		eax, testNum
cmp		checkNum, eax
jge		notComp
loop	testNumbers

compNumber:
ret							;returns to main if the number is composite

notComp:
inc		testNum
mov		checkNum, 2
loop	testNumbers


checkComp ENDP



;prints the results to screen
display PROC
;compares the temp counter to line display limit
cmp		temp, LINEDISPLAY
jge		newLine				;if greater than or equal to line display limit, it creates a new line
jl		sameLine


newLine:				;compares the temp counter to the line display limit. prints new line if greater than or equal to.
	call	CrLf
	mov		eax, testNum				;prints number
	call	WriteInt
	mov		edx, OFFSET space			;prints spaces
	call	WriteString
		
	inc		testNum				;adds 1 to make next number
	mov		checkNum, 2			;
	mov		temp, 0				;resets counter
	inc		temp				;increment line counter
	inc		counter				;adds 1 to number count
	ret

sameLine:							
	mov		eax, testNum			
	call	WriteInt
	mov		edx, OFFSET space
	call	WriteString
		
	inc		testNum				;adds 1 test number 
	mov		checkNum, 2			;resets the check number to set up next print
	inc		temp				;adds 1 to temporary counter to be checked against number display
	inc		counter				;adds 1 to number counter for the 
	ret

	
display ENDP


;displays the prompt for continue ad the goodbye messages
goodbye PROC

call	CrLf
mov		edx, OFFSET continue
call	WriteString
call	ReadInt
call	CrLf
mov		input, eax
cmp		eax, 1
je		userContinue
cmp		eax, 0
je		userNoContinue

userContinue:		;if the user would like to continue, it returns to main to re-print the next section
ret	

userNoContinue:		;if the user doesn't want to continue it will print the final goodbye message.
call	CrLf
mov		edx, OFFSET bye1
call	WriteString
call	CrLf
mov		edx, OFFSEt bye2
call	WriteString
call	CrLf
ret


goodbye ENDP

main PROC
call	intro
call	getNumber

printLoop:
call	checkComp
call	display
mov		eax, userNum
cmp		eax, counter		;compares userNum to number counter

;I tried to avoid the use of if/elseif here, but I couldn't get it to work without nesting the if statements so I decided to leave it in.
	.if		eax == counter		
		call	goodbye
		.if		input == 1
			mov		temp, 0			;resets temp to 0
			mov		counter, 0		;resets counter
			jmp		printLoop		;prints a new set of loops
		.elseif	input == 0
			jmp		exitProg
		.ENDIF
	.else							;keeps printing if eax != counter				
		jmp		printLoop
	.ENDIF

exitProg:
	exit		; exit to operating system

main ENDP

; (insert additional procedures here)

END main