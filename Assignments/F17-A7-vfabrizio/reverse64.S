.intel_syntax noprefix
.text
.global reverse_asm_64

reverse_asm_64:

push rbx

#rbx = headptr, rcx = nextptr, rdx = newheadptr
#headptr = nextptr = newheadptr = NULL
#rax is the scratch register
mov rax, 0x0
mov rbx, rax
mov rcx, rax
mov rdx, rax

#this is equivalent to if(head == NULL) return NULL;
mov rax, rdi
cmp rax, 0
je null_ret

add rax, rsi
#rbx is headptr
mov rbx, rax

#while loop
while_start:
#while (headptr)
cmp rbx, 0x0
je while_done

#nextptr = (void *)(*((unsigned long *)headptr));
mov rcx, [rbx]

# *(unsigned long *)headptr = (unsigned long)newheadptr;
mov [rbx], rdx

#newheadptr = headptr;
mov rdx, rbx

#headptr = nextptr;
mov rbx, rcx

#next iteration
jmp while_start

while_done:
mov rax, rdx
sub rax, rsi

null_ret:
pop rbx
ret
