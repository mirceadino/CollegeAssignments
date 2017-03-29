; Problem 14 - Main module

assume cs:code, ds:data

data segment public
	s1 db "mississippi"
	len1 equ $-s1
	end1 db '$'
	
	s2 db ""
	len2 equ $-s2
	end2 db '$'
	
	s3 db "iiippi"
	len3 equ $-s3
	end3 db '$'
	
	newline db 10, 13, '$'
	
	printS1Msg db "This is s1: $"
	printS2Msg db "This is s2: $"
	printS3Msg db "This is s3: $"
	
	output12Msg db "Longest suffix between strings s1 and s2 is: $"
	output13Msg db "Longest suffix between strings s1 and s3 is: $"
	output23Msg db "Longest suffix between strings s2 and s3 is: $"
data ends

code segment public
extrn suffix: proc

print macro sir
	push ax
	push dx
	mov ah, 09h
	lea dx, sir
	int 21h
	pop dx
	pop ax
endm

start:
	push data
	pop ds
	
	; print the strings s1, s2, s3
	print printS1Msg
	print s1
	print newline
	print printS2Msg
	print s2
	print newline
	print printS3Msg
	print s3
	print newline
	
	; setup and use "suffix" for strings s1 and s2
	lea bx, s1
	lea si, s2
	mov cx, len1
	mov dx, len2
	call suffix
	; print the longest common suffix of s1 and s2
	print output12Msg
	mov bx, len1
	sub bx, ax
	print s1[bx]
	print newline
	
	; setup and use "suffix" for strings s1 and s3
	lea bx, s1
	lea si, s3
	mov cx, len1
	mov dx, len3
	call suffix
	; print the longest common suffix of s1 and s3
	print output13Msg
	mov bx, len1
	sub bx, ax
	print s1[bx]
	print newline
	
	; setup and use "suffix" for strings s2 and s3
	lea bx, s2
	lea si, s3
	mov cx, len2
	mov dx, len3
	call suffix
	; print the longest common suffix of s2 and s3
	print output23Msg
	mov bx, len2
	sub bx, ax
	print s2[bx]
	print newline
	
finish:
	mov ax, 4c00h
	int 21h
code ends
end start
