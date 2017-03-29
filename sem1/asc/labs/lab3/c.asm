assume cs:code,ds:data
data segment
	a db -50
	b dw 100
	c db -100
	x dw ?
data ends
code segment
start:
	mov ax,data
	mov ds,ax
	; here starts the program
	mov al,a ; al = a = -50
	cbw      ; al is converted to word (ax = -50)
	add ax,b ; ax = ax + b = -50 + 200 = 150
	mov x,ax ; x = ax = 150
	mov al,c ; al = c = 200
	cbw      ; al is converted to word (ax = 200)
	sub x,ax ; x = x + ax = 150 - 200 = -50 which is 256-50 = 206
	; here ends the program
	mov ax,4C00h
	int 21h
code ends
end start
