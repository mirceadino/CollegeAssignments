assume cs:code,ds:data

data segment
	a db 12h
	b db 31h
	c dd 1AABBh
	d db 11h
	x dw ? ; cat
	y dw ? ; rest
data ends

; (a*b-c)/d
; (12h*31h-1AABBh)/11h

code segment
start:
	mov ax,data
	mov ds,ax
	; here starts the program
	mov al,a
	cbw ; ax <- a
	mov bx,ax ; bx <- a
	mov al,b
	cbw ; ax <- b
	cwd
	imul bx ; dx:ax <- a*b
	mov bx,dx
	mov cx,ax ; bx:cx <- a*b
	
	sub cx,word ptr c
	sbb bx,word ptr c+2 ; bx:cx <- a*b-c
	
	mov dx,bx ; dx:cx <- a*b-c
	mov al,d
	cbw ; ax <- d
	mov bx,ax ; bx <- d
	mov ax,cx ; dx:ax <- a*b-c
	idiv bx ; ax <- (a*b-c)/d
	mov x,ax ; x <- (a*b-c)/d
	mov y,dx ; y <- (a*b-c)%d
	; here ends the program
	mov ax,4C00h
	int 21h
code ends
end start
