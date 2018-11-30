TITLE Integer Accumulator     (IntegerAccumulator.asm)

; Author: Harrison Moore
; CS 271                 Date: 10/21/2018
; Description:	This program will Display the program title and programmer's name, get the user's name and greet the user;
;				Display instructions for the user, repeatedly prompt the user to enter a number, validate the user input;
;				to be in [-100, -1] (inclusive), count and accumulate the valid user numbers untill a non-ngative number;
;				is entered. (the non-negative number is discarded), calculate the (rounded integer) average of the negative;
;				numbers, Display the number of negative numbers entered, the sum of the negative numbers entered, the average;
;				rounded to the nearest integer, and a parting message (with the users name).;

INCLUDE Irvine32.inc

; (insert constant definitions here)
min = -100

.data

; (insert variable definitions here)
introMes BYTE "Welcome to the Integer Accumulator by Harrison Moore",0

nameMes BYTE "What is your name? ",0
inputName db 32 DUP(0)					;Gives us at least 31 characters to work with
hello BYTE "Hello, ",0

numMes1 BYTE "Please enter numbers in [-100, -1].",0
numMes2 BYTE "Enter a non-negative number when you are finished to see results.",0
entNum BYTE "Enter number: ",0
negNum DWORD ?

total DWORD ?
counter DWORD ?

errorMes BYTE "The number you entered was too small.",0

validMes1 BYTE "You entered ",0
validMes2 BYTE " valid numbers.",0

sumMes BYTE "The sum of your valid numbers is ",0

avgMes BYTE "The rounded average is ",0

thankyou BYTE "Thank you for playing Integer Accumulator! It's been a pleasure to meet you, ",0


.code
main PROC

; (insert executable instructions here)

; INTRODUCTION OF AUTHOR
mov edx, OFFSET introMes		;Displays Introduction
call writestring
call crlf

; USER INTRODUCTION
mov edx, OFFSET nameMes			;Displays 'what is your name' prompt
call writestring

mov edx, OFFSET inputName		;Gets input from user for their name
mov ecx, 31						;Sets their name can be 31 characters long
call ReadString

mov edx, OFFSET hello			;Displays hello,
call writestring
mov edx, OFFSET inputName		;Displays User Name
call writestring
call crlf

call crlf						;space for better looks.

; NUMBER INPUT
mov edx, OFFSET numMes1			;Displays message "please enter number in [-100, -1]"
call writestring
call crlf
mov edx, OFFSET numMes2			;Displays enter a non-neagative number to see results.
call writestring
call crlf

mov eax, negNum					;moves negNum to eax
mov ecx, 0						;zeroes out ecx for counter

; ERROR CHECK
errorZ:
	mov edx, OFFSET entNum		;Displays message to Enter Number:
	call writestring
	call readint
	mov negNum, eax				;moves userNumber to eax
	cmp eax, min				;compares eax to the smallest [-100]
	jl check					;If negNum is less than -100... jump down to error check loop
	cmp eax, -1					;compares eax to the largest [-1]
	jg doneDog					;if negNum is larger than -1, so is a positive.... jump down to done loop
	

	add counter, 1					;adds 1 to a counter of valid numbers entered


	neg eax


	add total, eax				;adds negNum to a running total
	jmp errorZ					;Runs through errorZ loop again

	

check:
	mov edx, OFFSET errorMes	;displays message about an incorrect input
	call writestring
	call crlf
	jmp errorZ					;jumps back to errorZ loop

; AVERAGE / TOTAL
doneDog:
	mov edx, OFFSET validMes1	;displays 1st half of valid numbers entered
	call writestring
	mov eax, counter				;moves counter to eax
	call WriteDec				;displays eax
;	mov ecx, eax				;moves counter to ecx
	mov edx, OFFSET validMes2	;displays 2nd half of valid numbers entered
	call writestring
	call crlf

	mov edx, OFFSET sumMes		;displays the message for the total of numbers
	call writestring
	mov eax, total				;moves running total to eax
	call WriteDec				;displays eax
	call crlf


	mov edx, OFFSET avgMes		;displays the message for the average of numbers
	call writestring

	mov edx, total
	cwd
	idiv counter				;divides running total in total by counter in counter

	call WriteDec				;displays eax after division
	call crlf

; END MESSAGE
	mov edx, OFFSET thankyou	;displays thank you message
	call writestring
	mov edx, OFFSET inputName	;display user name
	call writestring
	call crlf

	


main ENDP

; (insert additional procedures here)

END main
