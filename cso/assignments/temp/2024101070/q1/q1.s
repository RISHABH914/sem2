.section .text
.global solve

#r8 for storing n
#r9 for i initially
#r12 for temp sum
solve:
    movq %rdx,%r8
    movq $0,%r9
    movq $0,%r12

.initialise_sumarray:
    cmpq %r9,%r8
    je .loop

    addq (%rdi,%r9,8),%r12
    movq %r12,(%rsi,%r9,8)

    incq %r9
    jmp .initialise_sumarray

.loop:
    movq $0,%rax
    movq $0,%r9     #r9 for outer loop 
    movq $0,%r10    #r10 for inner loop
.innerloop:
    cmpq %r8,%r9
    jge .complete

     cmpq %r8,%r10
     jge .incouter

    cmpq $0,%r9
    je .leftzero

    movq %r9,%r12
    decq %r12
    movq (%rsi,%r10,8),%r13
    cmpq %r13,(%rsi,%r12,8)
    je .increment

    incq %r10
    jmp .innerloop

.increment:
    incq %rax
    incq %r10
    jmp .innerloop

.leftzero:
    cmpq $0,(%rsi,%r10,8)
    je .increment

    incq %r10
    jmp .innerloop

.incouter:
    incq %r9
    movq %r9,%r10
    jmp .innerloop

.complete:
    ret


