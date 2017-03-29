assume cs:code, ds:data

data segment
	endl db 13, 10, '$'
	readNrMsg db "Type number: $"
	textMsg db "Here's a nice text in a nice color.$"
	maxLenBuffer db 20
	lenBuffer db ?
	buffer db 20 dup(?)
	val dw ?
data ends

code segment

set_color macro col
	push ax
	push bx
	mov bx, col
	mov ax, 0900h
	int 10h
	pop bx
	pop ax
endm

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

read_buffer macro buff
	push ax
	push dx
	mov ah, 0ah
	lea dx, buff
	int 21h
	pop dx
	pop ax
endm

read_int macro buff, val
	local repeat
	local TEN
	TEN dw 10
	push ax
	push bx
	push cx
	push dx
	push si
	pushf
	read_buffer buff
	mov ax, 0
	mov val, 0
	mov ch, 0
	mov cl, buff[1]
	lea si, buff+2
	cld
	repeat:
		lodsb
		sub al, '0'
		mov bx, ax
		mov ax, val
		mov dx, 0
		imul TEN
		mov val, ax
		add val, bx
		loop repeat
	print endl
	popf
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
endm
	
start:
	push data
	pop ds
	
	print readNrMsg
	read_int maxLenBuffer, val
	set_color val
	print textMsg
	
	mov ax, 4c00h
	int 21h
code ends
end start
