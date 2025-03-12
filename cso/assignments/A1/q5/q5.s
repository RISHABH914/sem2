.section .text
.global solve

# r8 = arr, r9 = res, r10 = size (copied from rdx)
# r11 = lower 64 bits of product, r12 = zero count
# r13 = upper 64 bits of product (for 128-bit multiplication)
# r14 = another temp variable for size since rdx will be changed when doing division
solve:
    movq %rdi, %r8      #storing arr pointer 
    movq %rsi, %r9     #storing res pointer 
    movq %rdx, %r10     #storing size
    movq %rdx, %r14    #again storing the size to use in further blocks of code 
    movq $1, %r11       #r14 for computing the product of non zero elements therefore need to start with 1
    movq $0, %r12      #counting no of zeroes
    movq $0, %r13 

#this function counts no of zeroes as well as compute the product

.count_zeroes:
    cmpq $0, %r10           #if the array is traversed completely go to .complete 
    je .complete

    cmpq $0, (%r8)      #if the current element is 0 then increase 0 count by going to .add
    je .add

    movq %r11, %rax     # move current product to rax, need to do this since for 128 bit multiplication it multiplies given argument with %rax only
    mulq (%r8)          # multiply current non zero array element to rax 
    movq %rax, %r11     # store lower 64 bits to r11
    movq %rdx, %r13     # and higher 64 bits to r13

    # Perform modulo 2^64 to avoid overflow
    testq %r13, %r13    # Check if upper 64 bits (r13) are nonzero (overflow occurred)
    jz .no_overflow
    movq $0xFFFFFFFFFFFFFFFF, %rax  # Load 2^64 - 1
    andq %rax, %r11    # Take modulo by AND-ing with (2^64 - 1)
    movq $0, %r13      # Reset upper bits

.no_overflow:
    decq %r10           #decreasing remaining size array 
    addq $8, %r8        #incrementing array pointer
    jmp .count_zeroes   #looping

#basic part to increase count of zeroes whenever a zero element is found in the array
.add:
    incq %r12
    decq %r10
    addq $8, %r8
    jmp .count_zeroes

.complete:
    cmpq $2, %r12       # if zero count >=2 then set all res to 0 
    jge .allzero

    cmpq $1, %r12       # if exactly 1 zero, handle separately using .onezero
    je .onezero

    movq %rdi, %r8      # Reset array pointer
    movq %r14, %r10     # Restore size from r14
    jmp .division       # Proceed with division

.division:
    cmpq $0, %r10           #base case for looping
    je .finaldone

    movq %r11, %rax     # Load product (lower 64 bits) into rax
    movq %r13, %rdx     # Load upper 64 bits into RDX
    idivq (%r8)         # doing division 
    movq %rax, (%r9)    # Store quotient in result
    addq $8, %r9        # Move to next result position
    addq $8, %r8        # Move to next input position
    decq %r10
    jmp .division

# part for handling the case where only one zero is found in the array
.onezero:
    cmpq $0, %r14       #base case for looping instead of rdx or r10 using r14 since both may hve been changed
    je .finaldone

    cmpq $0, (%rdi)     # if the element is zero then res will be product of non zeroe elements which we already computed 
    je .giveprod

    movq $0, (%r9)      #result will be zero for non zero elements 
    addq $8, %r9
    addq $8, %rdi       #basic incremention for the original, res array along with decreasing size of remaining part
    decq %r14
    jmp .onezero

.giveprod:
    movq %r11, (%r9)    # since r11 was storing the result thus moving r11 to res pointer
    addq $8, %r9
    addq $8, %rdi       # incrementing pointers and decreasing remaining size
    decq %r14
    jmp .onezero

# part for giving complete result as 0
.allzero:
    cmpq $0, %r14       
    je .finaldone
    movq $0, (%r9)
    addq $8, %r9
    decq %r14
    jmp .allzero

.finaldone:
    ret
