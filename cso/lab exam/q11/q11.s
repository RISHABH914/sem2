.section .text
.global q11

#void q11(long long int n,long long int* arr,long long int* res,long long int* stack);
q11:
    movq $-1,(%rdx)
    movq $1,%r8     #for i of array loop
    movq $0,%r9     #for index of stack

.loop:
    cmpq %r8,%rdi
    jle .done

    movq %r9,%r10
    decq %r10
    cmpq $0,%r10
    jl .returnminus1

    movq (%rcx,%r10,8),%r11
    cmpq (%rsi,%r8,8),%r11
    jg .found

    jmp .pop

.found:
    movq %r11,(%rdx,%r8,8);
    movq (%rsi,%r8,8),%r11
    incq %r8
    movq %r11,(%rcx,%r9,8)
    incq %r9
    jmp .loop

.pop:
    decq %r9
    jmp .loop

.returnminus1:
    movq $-1,(%rdx,%r8,8)
    movq (%rsi,%r8,8),%r12
    movq %r12,(%rcx,%r9,8);
    incq %r9
    incq %r8
    jmp .loop

.done:
    ret