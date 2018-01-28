.intel_syntax noprefix
.text
.global toggle_bit

toggle_bit:

#rdi = long num and rsi = bit_num = bit to toggle
#check bit_num is between 0 and 63
cmp rsi, 0x3f
jbe toggle
# not then put 0 in rax and exit
mov rax, 0x0
jmp exit

toggle:
# num = num ^(1 << bit_num);
mov rax, rsi
mov rdx, 0x1
mov rcx, rax
shl rdx, cl
mov rax, rdx

xor rdi, rax
mov rax, rdi


exit:

ret