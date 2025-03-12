.section .text
.global find

#%r8 for storing remaining size
#%r9 for storing the element pointer
find:
    imulq $3,%rsi
    addq $1,%rsi
    movq %rsi,%r8
    movq %rdi,%r9

.outerloop:
    cmpq $0,%r8
    je .done
    movq $0,%r10            #for storing count of that particular number
    movq %rdi,%r11             #r11 for storing start of array for inner loop
    movq %rsi,%r12                #size for inner loop
    jmp .innerloop


.innerloop:
    cmpq $0,%r12
    je .innercomplete
    movq (%r11),%r13
    cmpq %r13,(%r9)
    je .add

    decq %r12
    addq $8,%r11
    jmp .innerloop

.innercomplete:
    decq %r8
    addq $8,%r9
    jmp .outerloop

    
.add:
    incq %r10
    cmpq $2,%r10
    jge .giveres
    addq $8,%r11
    decq %r12
    jmp .innerloop

.giveres:
    movq (%r9),%rax
    ret

.done:
    movq $-1,%rax
    ret