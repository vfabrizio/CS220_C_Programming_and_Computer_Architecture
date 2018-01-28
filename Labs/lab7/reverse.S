.intel_syntax noprefix
.text
.global reverse_asm

reverse_asm:
push ebx
# ebx for headptr, ecx for nextptr, and edx for newheadptr
#reversal code starts
#pop ebx
#ret

#headptr = nextptr = newheadptr = NULL
#we use eax as the scratch register
mov eax, 0x0
mov ebx, eax
mov ecx, eax
mov edx, eax

#this is equivalent to if(head == NULL) return NULL;
mov eax, [esp + 0x8]
cmp eax, 0
je null_ret

#step 6
add eax, [esp + 0xc]
#ebx is headptr
mov ebx, eax

#make while loop step 7
while_start:
#while (headptr)
cmp ebx, 0x0
je while_done

#nextptr = (void *)(*((unsigned long *)headptr));
mov ecx, [ebx]

# *(unsigned long *)headptr = (unsigned long)newheadptr;
mov [ebx], edx

#newheadptr = headptr
mov edx, ebx

#headptr = nextptr
mov ebx, ecx

#next iteration
jmp while_start

while_done:
#code that follows while loop
mov eax, edx
sub eax, [esp + 0xc]

null_ret:
pop ebx
ret

