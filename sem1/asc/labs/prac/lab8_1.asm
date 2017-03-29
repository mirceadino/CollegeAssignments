ASSUME CS:CODE, DS:DATA

DATA SEGMENT
	string db 43, 123, 44, 0, 112, 44, 4, 8, 16
	len equ $-string
	buffer db 8 dup(?)
	newline db 10, 13, '$'
DATA ENDS

CODE SEGMENT
print MACRO buffer	
	push ax
	push dx
	mov ah, 09h
	lea dx, buffer
	int 21h
	pop dx
	pop ax
ENDM

println MACRO buffer
	print buffer
	print newline
ENDM

to_binary MACRO number, buffer
	push ax
	push bx
	push cx
	push di
	mov ax, number
	mov cx, 1
	push '$'
	divide:
		mov bx, 0
		shr ax, 1
		adc bx, '0'
		push bx
		inc cx
		cmp ax, 0
		jne divide
		
	lea di, buffer
	remake:
		pop ax
		stosb
		loop remake
	pop di
	pop cx
	pop bx
	pop ax
ENDM

start:
	mov ax, data
	mov ds, ax
	mov es, ax
	
transform_and_print:
	mov cx, len
	lea si, string
	mov ax, 0
	printloop:
		lodsb
		to_binary ax, buffer
		println buffer
		loop printloop
		
finish:
	mov ax, 4C00h
	int 21h
CODE ENDS
END start
