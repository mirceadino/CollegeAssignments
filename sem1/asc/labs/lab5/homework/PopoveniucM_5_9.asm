;NAME Popoveniuc Mircea, gr. 911, 29.10.2015, homework for lab 5, problem 9

assume cs:code,ds:data

data segment
	a dw 1010111001101100b
	b db 00100110b
	c db ?
data ends

code segment
start:
	push data
	pop ds
	; here starts the program
	
	; initialize c as 00000000b
	mov c, 0
	
	; the bits 0-3 of c are the same as bits 6-9 of a
	mov ax, a ; move a to ax
	and ax, 0000001111000000b ; isolate bits 6-9 of ax
	shr ax, 6; shift bits 6-9 of ax to positions 0-3 (they are now bits 0-3 of al)
	or c, al ; set the bits 0-3 in c the same as bits 0-3 of al
	
	; the bits 4-5 of c have the value 1
	or c, 00110000b ; set the bits 4-5 of c as 1
	
	; the bits 6-7 of c are the same as the bits 1-2 of b
	mov al, b ; move b to al
	and al, 00000110b ; isolate bits 1-2 of al
	shl al, 5 ; shift bits 1-2 of al to positions 6-7
	or c, al ; set the bits 6-7 in c the same as bits 6-7 in al
	
	; here ends the program
	mov ax,4C00h
	int 21h
code ends
end start
