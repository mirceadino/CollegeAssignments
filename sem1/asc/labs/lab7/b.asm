assume cs:code, ds:data

data segment
	s dd 12345678h,5bcfh,45327h,1798dfeh,0f112233h
	lens equ ($-s)/4
	d db 4*lens/3+1 dup(?)
	lend equ $-d
data ends

code segment
start:
	mov ax, data
	mov ds, ax
	mov es, ax
	
	; move the bytes from s, which are on the position of multiples of 3, to d
	
	mov si, offset s
	mov di, offset d
	mov cx, lend
	
	repeat:
		movsb
		add si, 2
		loop repeat
	
	; sort d in ascending order
	
	mov cx, lend
	
	bubblesort:
		push cx
		
		mov si, offset d
		mov cx, lend-1
		
		iterate:
			lodsb
			mov ah, al ; ah := ith byte
			lodsb      ; al := i+1th byte
			dec si     
			cmp ah, al
			jng dontswap
			
			; swap ith byte with i+1th byte if the pair of bytes is in descending order
			
			mov byte ptr [si-1], al
			mov byte ptr [si], ah
			
			dontswap:
				loop iterate
				
		pop cx
		loop bubblesort
	
	mov ax, 4c00h
	int 21h
code ends
end start
