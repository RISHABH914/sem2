.section .text
.global solve

#r8 for storing n since we will be looping from last element
#r9 for storing index of top of stack
solve:
    movq %rcx,%r8
    movq $-1,%r9
    decq %r8

.loop:
    cmpq $0,%r8
    jl .done
    cmpq $-1,%r9
    je .foundnone

    movq (%rdi,%r8,8),%r10
    movq (%rsi,%r9,8),%r11

    cmpq %r10,%r11
    jg .found

    decq %r9
    jmp .loop

.found:
    movq %r11,(%rdx,%r8,8)
    incq %r9
    movq %r10,(%rsi,%r9,8)

    decq %r8
    jmp .loop

.foundnone:
    movq $-1,(%rdx,%r8,8)
    incq %r9
    movq (%rdi,%r8,8),%r10
    movq %r10,(%rsi,%r9,8)

    decq %r8
    jmp .loop

.done:
    ret

