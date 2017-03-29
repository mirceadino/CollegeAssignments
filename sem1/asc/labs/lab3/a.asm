assume cs:code,ds:data
data segment
	a db 15
	b db 17
	x db ?
data ends
code segment
start:
	mov ax,data
	mov ds,ax
	; here starts the program
	mov al,a ; al = a = 15
	add al,b ; al = al + b = 15 + 17 = 32
	mov x,al ; x = al = 32
	; here ends the program
	mov ax,4C00h
	int 21h
code ends
end start
