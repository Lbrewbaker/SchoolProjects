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
DISPLAY = 10

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

printArray PROC

END main