;NAME Popoveniuc Mircea, gr. 911, 2.10.2015, homework for lab 4, problem 27 - unsigned interpretation

assume cs:code,ds:data

; (100+a+b*c)/(a-100)+e
; a,b-byte; c-word; e-doubleword

data segment
	a db 15
	b db 127
	c dw 32
	e dd 454
	result dd ? ; here's gonna be the result
data ends

code segment
start:
	mov ax,data
	mov ds,ax
	; here starts the program
	
	; perform b*c
	mov al,b ; al <- b
	mov ah,0 ; al is converted to word => ax <- b
	mul c   ; dx:ax <- b*c
	
	; add a to dx:ax
	mov cx,ax  ; dx:cx <- b*c
	mov al,a   ; al <- a
	mov ah,0   ; al is converted to word => ax <- a
	add cx,ax
	adc dx,0   ; dx:cx <- b*c+a
	mov ax,cx  ; dx:ax <- b*c+a
	
	; add 100 to dx:ax
	add ax,100
	adc dx,0   ; dx:ax <- b*c+a+100
	
	; compute a-100
	mov cx,ax  ; cx holds ax
	mov al,a   ; al <- a
	mov ah,0   ; al is converted to word => ax <- a
	mov bx,ax  ; bx <- a
	mov ax,cx  ; cx returns ax
	sub bx,100 ; bx <- a-100
	
	; divide dx:ax by cx
	div bx   ; ax <- (a+100+b*c)/(a-100)
	mov dx,0 ; ax is converted to dword => dx:ax <- (a+100+b*c)/(a-100)

	; add e to dx:ax
	add ax,word ptr e
	adc dx,word ptr e+2 
	
	; move final result
	mov word ptr result,ax
	mov word ptr result+2,dx
	
	; here ends the program
	mov ax,4C00h
	int 21h
code ends
end start
