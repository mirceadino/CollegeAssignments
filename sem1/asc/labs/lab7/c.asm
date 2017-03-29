assume cs:code, ds:data

data segment
	a db 'bcdefgha'
	len equ $-a
data ends

code segment
start:
	mov ax, data
	mov ds, ax
	
	; start from the end
	sub si, si
	add si, len-1
	
	repeat:
		; separate the pair of bytes i-1 in al and i in bl
		sub ax, ax
		sub bx, bx
		add al, byte ptr [si-1]
		add bl, byte ptr [si]
		
		; swap the bytes		
		add byte ptr [si-1], bl
		sub byte ptr [si-1], al
		add byte ptr [si], al
		sub byte ptr [si], bl
		
		; go to the previous byte
		sub si, 1
		
		cmp si, 0
		ja repeat
	
	mov ax, 4c00h
	int 21h
code ends
end start
