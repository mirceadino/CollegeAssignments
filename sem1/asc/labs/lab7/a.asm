assume cs:code, ds:data

data segment
	a dw 1234h, 5678h, 90h
	lena equ ($-a)/2
	b dw 4h, 0abcdh, 10h, 1122h
	lenb equ ($-b)/2
	c db lena+lenb dup(?)
	lenc equ $-c
data ends

code segment
start:
	mov ax, data
	mov ds, ax
	mov es, ax
	
	; move the most significant bytes of the words from a to c
	
	mov si, offset a
	mov di, offset c
	mov cx, lena
	
	repeat1:
		movsb
		inc si
		loop repeat1
		
	; move the least significant bytes of the words from b to c
	
	mov si, 1+offset b
	mov cx, lenb
	
	repeat2:
		movsb
		inc si
		loop repeat2
	
	; sort c in ascending order
	
	mov cx, lenc
	
	bubblesort:
		push cx
		
		mov si, offset c
		mov cx, lenc-1
		
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
