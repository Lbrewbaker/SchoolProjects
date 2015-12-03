TITLE Program 6(Option B)		(program6.asm)

; Program Description: low level I/O Procedures and implementing recurssion passing parameters on system stack
; Author: Luke Brewbaker
; Date Created: 28 Nov 15
; Last Modification Date: 2 Dec 15

INCLUDE Irvine32.inc

getString MACRO		a, x
;used get string from user.  
	push	ecx
	push	edx
	mov		edx, a
	mov		ecx, x
	call	ReadString
	pop		edx
	pop		ecx
ENDM

mwriteArray	MACRO a
	push	edx
	push	eax
	mov		edx, OFFSET a
	call	WriteString
	pop		edx
	pop		eax
ENDM

mwriteString	MACRO a
	push	edx
	push	eax
	mov		edx, OFFSET a
	call	WriteString
	call	CrLf
	pop		edx
	pop		eax
ENDM

;global constants
MAXSIZE = 1000
INPUTSIZE = 10

.data

intro		BYTE	"Low level I/O procedures.  By Luke Brewbaker", 0
bye			BYTE	"Good bye!", 0
prompt		BYTE	"Please provide 10 unsigned integers over 1", 0
prompt2		BYTE	"Please enter an integer over 1: ", 0
invalidInp	BYTE	"Input is invalid. Please try again. ", 0

arrayDisp	BYTE	"Your numbers are: ", 0
sumDisp		BYTE	"The sum of your numbers is: ", 0
averageDisp	BYTE	"The average of your numbers is: ", 0

array		DWORD	INPUTSIZE DUP(?)
userInput	DWORD	MAXSIZE	DUP(?)
userString	DWORD	MAXSIZE DUP(?)
space		BYTE	" ", 0
sum			DWORD	?
average		DWORD	?
temp		DWORD	?   ; = temp_count
temp2		DWORD	?
temp3		DWORD	?


.code
;main procedure
main PROC

call	introduction

;numbers input as a string, but converted to an int.

mov		temp, 1
call	getNumbers
call	calculate

;display procs
mwriteString arrayDisp
call	display

;goodbye proc
call adios

	exit		; exit to operating system
main ENDP

;introduction proc
introduction PROC
	
;use the macro to write the string to console
	mwriteString	intro
	mwriteString	prompt
	ret

introduction ENDP

;goodbye procedure
adios	PROC
	mwriteString bye
	ret
adios ENDP

;retrieve the numbers from the user
getNumbers PROC
	
	mov		esi, OFFSET array
	mov		ecx, INPUTSIZE
numberLoops:
	call	readNums
	cmp		temp, INPUTSIZE+1
	je		done
	loop	numberLoops
done:
	ret
getNumbers ENDP


;read the numbers
readNums PROC
	
getInput:
mwriteString	prompt2
mov				temp3, (sizeof userInput)-1
getString		OFFSET userInput, temp3

mov		esi, OFFSET userinput
mov		eax, 0
mov		ebx, 10
mov		ecx, 0

;converts to int
convert:
	lodsb				;byte from esi goes to ax
	cmp		ax, 0
	je		done		;marks the end of the string

	cmp		ax, 30h
	jb		invalid
	cmp		ax, 39h
	ja		invalid

valid:
	sub		ax, 30h		;convert to int
	xchg	eax, ecx
	mul		ebx
	jc		invalid		;too big of a number

	xchg	eax, ecx	;moves back to eax
	add		ecx, eax	
	jmp		convert		;continues

invalid:
	mwriteString invalidInp
	jmp		getInput

done:
	mov		esi, 0
	.if		temp == 1
		mov		array[esi], ecx
	.else
		mov		eax, temp
		mov		temp2, eax
		dec		temp2
		mov		eax, temp2
		mov		ebx, sizeof DWORD
		mul		ebx
		add		esi, eax
		mov		array[esi], ecx
	.endif

inc temp
ret

readNums ENDP

calculate PROC
	mov		esi, OFFSET array
	mov		ecx, INPUTSIZE
	mov		eax, 0

calcLoop:
	add		eax, [esi]
	add		esi, sizeof DWORD
	loop	calcLoop
	mov		sum, eax
	mov		ebx, 10
	div		ebx
	mov		average, eax
	ret

calculate ENDP

writeVal PROC
	mov		esi, OFFSET array
	mov		ecx, INPUTSIZE

displayLoop:
	mov		eax, [esi]
	call	WriteDec

	cmp		ecx, 1
	je		done
	jne		dispMore

dispMore:
	mwriteArray OFFSET space
	add		esi, sizeof DWORD
	loop	displayLoop

done:
	ret

writeVal ENDP


;displays the sum and average
display PROC

call	WriteVal
call	CrLf

;display sum
mov		edx, OFFSET sumDisp
call	WriteString
mov		eax, sum
call	WriteDec
call	CrLf

;display average
mov		edx, OFFSET averageDisp
call	WriteString
mov		eax, average
call	WriteDec
call	Crlf
ret

display ENDP


END main