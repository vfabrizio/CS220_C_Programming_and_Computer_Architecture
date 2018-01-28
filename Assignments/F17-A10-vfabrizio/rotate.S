.intel_syntax noprefix
.text
.global rotate

rotate:

push rbp
mov rbp, rsp

#rdi = val that needs to be shifted
#rsi = num <- number of times that it needs to be shifted
#rdx = direction to shift, 0 = right shift, 1 = left shift
mov rax, 0x0
cmp rsi, 0x0
jz done

#num=num%64
#num%64 = num & (64-1)
mov rcx, 0x0
mov rcx, rsi
and rcx, 63

cmp rdx, 0x1
je left_shift

#otherwise can just right shift here
ror rdi, cl
mov rax, rdi
jmp done


left_shift:
rol rdi, cl
mov rax, rdi
jmp done


done:
pop rbp
ret