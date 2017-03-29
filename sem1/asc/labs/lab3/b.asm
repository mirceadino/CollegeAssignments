assume cs:code,ds:data
data segment
	a dw 500
	b db -100
	x dw ?
data ends
code segment
start:
	mov ax,data
	mov ds,ax
	; here starts the program
	mov al,b ; al = b = 100
	cbw      ; al is converted to word (ax = 100)
	add ax,a ; ax = ax + a = 100 + 500 = 600
	mov x,ax ; x = 600
	; here ends the program
	mov ax,4C00h
	int 21h
code ends
end start
