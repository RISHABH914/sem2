# %rdi - pointer to input array (nums)
# %rsi - pointer to output array (result)
# %rdx - size of array (n)
#product except self
.section .text
.global productExceptSelf
#r10 for storing array,r11 for storing result pointer,r12 for size
productExceptSelf:

    # Save arguments
    movq %rdi, %r10   # moving array pointer to r10
    movq %rsi, %r11    #moving res pointer to r11
    movq %rdx, %r12   #moving size value to r12

    # Initialize result array with 1s
    movq $0,%rcx    # i for the loop
    movq $1,%rax        #rax for storing the left porduct as of now

#looping from 0 to n-1
prefix_product:
    cmpq %r12, %rcx
    jge prefix_done

    movq %rax, (%r11,%rcx,8)    # result[i] = prefix as of now then will mutiply with suffix_product hence getting the right answer

    movq (%r10,%rcx,8), %rbx    # rbx = nums[i]
    imulq %rbx, %rax            # prefix *= nums[i]

    # Handling overflow
    movq $0x7FFFFFFFFFFFFFFF, %rbx  # storing long long max value into rbx
        #following is the standard way to divide by sign extending
    cqto                       # Sign-extend %rax into %rdx:%rax
    idivq %rbx                 # Divide by rbx which stores long long max
    movq %rdx, %rax            # store the modulated value again to rax since rdx stores the remainder and rax stores the quotient after division thereofore storing rdx to rax for further looping

    incq %rcx
    jmp prefix_product

prefix_done:

    movq $1, %rax      # resetting for right suffix
    decq %r12          # n-1 size for looping

#since for right suffix we need to iterate from n-1 to 0 therefore need to change the looping variable


suffix_product:
    cmpq $-1, %r12
    jle suffix_done

    movq (%r11,%r12,8), %rbx    # rbx = result[i]
    imulq %rax, %rbx            # rbx*=suffix
        movq %rbx, (%r11,%r12,8)    # put result[i]=rbx

    movq (%r10,%r12,8), %rbx    # rbx = nums[i]
    imulq %rbx, %rax            # suffix *= nums[i], normal updation for suffix

    # handling overflow with long long max
    movq $0x7FFFFFFFFFFFFFFF, %rbx      #storing long long max value in rbx

        #followig is the standard way to devide by sign extending

    cqto                                #sign extend and storing it into %rdx:%rax
    idivq %rbx                          #dividing by long long max
    movq %rdx, %rax                     #store the modulated value again to rax since rdx stores the remainder... whatever i wrote above same text is here as well

    decq %r12                           #i--
    jmp suffix_product
suffix_done:
    ret
