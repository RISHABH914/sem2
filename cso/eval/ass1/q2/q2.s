.section .text
.global solve
#for moving array by two places
#%r8 stores temp arr
#%r9 stores temp res
#%r10 for storing the remaining size
solve:
    cmpq $0,%rdx        #for base case if initial given size if less than equal to 0 then retur -1
    jle .error          #calls a function to return -1

    cmpq $1,%rdx        #if size is just 1 then return the only given element
    je .one

    cmpq $2,%rdx        #if size if 2 then also return the same array as it is since moving 2 steps will lead to the same thing
    je .two

    movq %rdi,%r8       #then storing the respective variables to their required temp registers
    movq %rsi,%r9
    addq $16,%r9        #storing first element of arr to 3rd index of res and so on till end of res array is not reached(indirectly)
    movq %rdx,%r10
    jmp .loop

#function for handling the n=1 part
.one:
    movq (%rdi),%rdx
    movq %rdx,(%rsi)
    ret

#function for handling n=2 part
.two:
    movq (%rdi),%rdx
    movq %rdx,(%rsi)
    movq 8(%rdi),%rdx
    movq %rdx,8(%rsi)
    ret

#this should not happend but just for a verification so that size of array does not become less than 1
.error:                 #function for returning -1 as the answer in case of size of array is less than 1
    movq $-1,%rax
    ret

.loop:
    cmpq $2,%r10        #for looping till end of res array, therefore when 2 elements of arr will be left
    je .done

    movq (%r8),%rdx     #moving current element of array to res at 2 index next to current index of array
    movq %rdx,(%r9)     #in short if the current index of arr is i then res[i+2]=arr[i], since res was 2 indexes ahead already
    decq %r10           #decreasing remaining array of arr array
    addq $8,%r8
    addq $8,%r9
    jmp .loop


.done:
    movq (%r8),%rdx         #for processing remaining 2 elements
    movq %rdx,(%rsi)        #move 2nd last element of arr to starting of res
    movq 8(%r8),%rdx
    movq %rdx,8(%rsi)       #move last element of res to 2nd index of the res
    ret