TITLE Program 5		(program5.asm)

; Program Description: Random number generator
; Author: Luke Brewbaker
; Date Created: 9 Nov 11
; Last Modification Date: 15  Nov 11

INCLUDE Irvine32.inc


MIN = 5
MAX = 200
LOW = 1
HI = 999
LINEDISPLAY = 10

.data

intro		BYTE	"Random Number Generator. By Luke Brewbaker",0
intro2		BYTE	"This program will generator a random number between 1 and 999",0
intro3		BYTE	"It will store any number of numbers of your choose, and store them in an array.  It will also show you an unsorted array, sorted array in decending order, and calculate the median value. ", 0
prompt		BYTE	"Please enter how many numbers you'd like generated(5-200): ",0
invalid		BYTE	"That input is not valid.  Please enter a valid input. ",0
dispUnsort	BYTE	"Unsorted array results: ",0
dispSort	BYTE	"Sorted array results: ",0
dispMed		BYTE	"Median result: ",0

array		DWORD	MAX DUP(?)
arraySpace	DWORD	" ",0
inputNum	DWORD	?
counter		DWORD	?


.code
main PROC

call		Randomize			;irvines random number generator
call		introductions		;calls the introduction sequence
call		input				;calls the input sequence
call		arrayfill			;calls the array fill sequence

;prints the array
mov			edx, OFFSET dispUnsort
call		WriteString		
mov			ecx, OFFSET	array
call		printArray
call		CrLf

;sort the array
call		sortArray
mov			edx, OFFSET dispSort
call		WriteString
mov			ecx, OFFSET array
call		printArray

;display median calculation




	exit		; exit to operating system
main ENDP

;Displays introduction messages to the user
introductions PROC

mov		edx, OFFSET intro
call	WriteString
Call	CrLf
mov		edx, OFFSET intro2
call	WriteString
call	CrLf
mov		edx, OFFSET intro3
call	WriteString
call	CrLf
ret

introductions ENDP

;gets user input for array size and number of numbers to randomly generate
input PROC

mov		edx, OFFSET prompt
call	WriteString
call	ReadInt
cmp		eax, MIN
JL		badNumber
cmp		eax, MAX
jg		badNum

badNum: ;number not within range
mov		edx, OFFSET invalid
call	WriteString
call	input

goodNum: ;if number is within range
mov		inputNum, eax
ret
input ENDP

;fill array with the contents
arrayfill PROC

mov		ecx, inputNum		;set the counter based on users input
mov		esi, 0				;reset ESI

randomNumGen:
mov		eax, HI
sub		eax, LO
inc		eax
call	RandomRange
add		eax, LO				;a random number should now be in the EAX position

mov		array[esi*sizeof DWORD], eax	;moves the random number into the array allocation
inc		esi								;prepares for next number
loop	randomNumGen
ret

arrayfill ENDP


;sequence to print the array to the console
printArray PROC

;arrange register to print correctly
mov		eax, O
mov		esi, 0
mov		counter, 0
mov		ecx, inputNum

display:
cmp	counter, LINEDISPLAY ;compares the counter to the line display limit
je		newLine

	newLine:
	mov		counter, 0
	call	CrLf

mov		eax, array[esi*sizeof DWORD]		;gets number at the position specified by counter
call	WriteDec							;displays that number
mov		edx, OFFSET arraySpace		
call	WriteString
inc		esi										
inc		counter
loop	display								;loops to display again
call	CrLf


ret											;returns to main
printArray ENDP


;I use a bubble sort to sort array inputs because it is typically the fastest in terms of execution time
;I found an algorithm online that I am going to use for this purpose found here: http://bcs.solano.edu/workarea/jurrutia/Coursework/CIS%2020%20-%20Assembly%20Programming/Irvine%20X86%20Processors/Ex%20Prgms%20and%20Libs/Examples/ch09/32%20bit/Binary_Search/BubbleSort.asm
sortArray PROC

mov		ecx, InputNum
dec		ecx

L1:
push	ecx
mov		esim OFFSET array

L2:


sortArray ENDP


END main