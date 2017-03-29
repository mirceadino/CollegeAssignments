assume cs:code,ds:data

data segment
	a dw 1010111001101100b
	b dw 0111110100100110b
	c dw ?
data ends

code segment
start:
	push data
	pop ds
	; here starts the program
	
	mov c, 0
	
	; set bit 0 of c as bit 0 of a
	mov ax, a ; move a to ax
	and ax, 0000000000000001b ; isolate bit 0
	or c, ax
	
	; set bit 2 of c as bit 1 of a
	mov ax, a ; move a to ax
	and ax, 0000000000000010b ; isolate bit 1
	shl ax, 1 ; bit 2 is now bit 1
	or c, ax 
	
	; set bit 1 of c as bit 1 of b
	mov ax, b ; move b to ax
	and ax, 0000000000000010b ; isolate bit 1
	or c, ax
	
	; set bits 3-5 of c as 010
	mov ax, 0000000000010000b
	or c, ax
	
	; set bits 6-9 of c as bits 11-14 of a
	mov ax, a ; move a to ax
	and ax, 0111100000000000b ; isolate bits 11-14
	shr ax, 5 ; bits 11-14 are now bits 6-9
	or c, ax
	
	; set bits 10-15 of c as bits 3-8 of b
	mov ax, b ; move b to ax
	not ax ; invers bits
	and ax, 0000000111111000b ; isolate bits 3-8
	shl ax, 7 ; bits 3-8 are now bits 10-15
	or c, ax
	
	; here ends the program
	mov ax,4C00h
	int 21h
code ends
end start
