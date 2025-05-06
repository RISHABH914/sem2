.section .text
.global q5

#long long int q5(long long int n,long long int* arr,long long int* res);
q5:
    movq (%rsi),%r8
    movq %r8,(%rdx)

    movq $1,%r8         #r8 for i in loop
    movq (%rsi),%r9     #r9 for previous element in loop
    movq $1,%r11

.loop:
    cmpq %r8,%rdi
    jle .done

    movq (%rsi,%r8,8),%r10
    cmpq %r10,%r9
    je .increment

    movq %r10,(%rdx,%r11,8)
    movq %r10,%r9
    incq %r11
    jmp .increment

.increment:
    incq %r8
    jmp .loop

.done:
    movq %r11,%rax
    ret

