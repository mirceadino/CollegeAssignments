;NAME Popoveniuc Mircea, gr. 911, 15.10.2015, homework for lab 3, problem 3 - signed interpretation
assume cs:code, ds:data
data segment
	m db 50   ; m in [0, 100]
	h dw 200  ; h in [100, 300]
	yy dw 200 ; yy in [0, 256]
	d db -1   ; d in [-3, 15]
	result dw ? ; result = (h+h+d)-(yy+m)
data ends
code segment
start:
	mov ax,data
	mov ds,ax
	; here starts the program
	
	mov al,d ; al = d = -1
	cbw      ; al is converted to word (ax = -1)
	
	add ax,h ; ax = ax + h = -1 + 200 = 199
	
	add ax,h ; ax = ax + h = 199 + 200 = 399
	
	mov result,ax ; result = ax = 399
	; result currently stores (h+h+d)
	
	mov al,m ; al = m = 50
	cbw      ; al is converted to word (ax = 50)
	
	add ax,yy ; ax = ax + yy = 50 + 200 = 250
	; ax currently stores (yy+m)
	
	sub result,ax ; result = result - ax = 399 - 250 = 149
	; result currently stores (h+h+d)-(yy+m)
	
	; here ends the program
	mov ax,4C00h
	int 21h
code ends
end start
