ASSUME CS:CODE, DS:DATA

DATA SEGMENT
	endl db 10, 13, '$'
	number db 6 dup(?)
	TEN db 10
DATA ENDS

CODE SEGMENT
print macro msg
	push ax
	push dx
	mov ah, 09h
	lea dx, msg
	int 21h
	pop dx
	pop ax
endm

println macro msg
	print msg
	print endl
endm

get_base_10 macro value
	push ax
	push bx
	push cx
	push di
	
	mov ax, value
	mov cx, 3
	
	push '$'
	push ax
	push ' '
	
	divide:
		div TEN
		mov bl, ah
		mov bh, 0
		add bx, '0'
		push bx
		mov ah, 0
		inc cx
		cmp ax, 0
		jne divide
		
	lea di, number
	
	make_str:
		pop ax
		stosb
		loop make_str
	
	pop di
	pop cx
	pop bx
	pop ax
endm

start:
	mov ax, data
	mov ds, ax
	mov es, ax	
	
set_loop:
	mov cx, 126-32+1
	mov ax, 32

repeat:
	get_base_10 ax
	println number
	inc ax
	loop repeat

finish:
	mov ax, 4C00h
	int 21h
CODE ENDS
END start
