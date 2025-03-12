.section .text
.global solve

#%r8 stores temp arr
#%r9 stores temp res
#%r10 for storing the remaining size
solve:

    cmpq $1,%rdx
    je .one

    cmpq $2,%rdx
    je .two

    movq %rdi,%r8
    movq %rsi,%r9
    addq $16,%r9
    movq %rdx,%r10
    jmp .loop


.one:
    movq (%rdi),%rdx
    movq %rdx,(%rsi)
    ret

.two:
    movq (%rdi),%rdx
    movq %rdx,(%rsi)
    movq 8(%rdi),%rdx
    movq %rdx,8(%rsi)
    ret

.loop:
    cmpq $2,%r10
    je .done

    movq (%r8),%rdx
    movq %rdx,(%r9)
    decq %r10
    addq $8,%r8
    addq $8,%r9
    jmp .loop


.done:
    movq (%r8),%rdx
    movq %rdx,(%rsi)
    movq 8(%r8),%rdx
    movq %rdx,8(%rsi)
    ret