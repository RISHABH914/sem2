.section .text
.global max

#%rdi stores the address of the starting of the array
#%rsi stores the size of the array
#%rax will store the max value of the array and then final result
#%r10 stores the minimum element of the array


max:
    cmpq $0,$rsi        #for base case if initial given size if less than equal to 0 then retur -1
    jle .error          #calls a function to return -1

    movq %rsi,%r8       #making a temporary copy of starting address of the register
    movq %rdi,%r9       #similarly making a copy of size of the array

    movq (%r9),%rax     #initialising max with first element of the array
    addq $8,%r9         #since the array store long long values which are of 8 bytes hence we need to move the address of the array by 8 bytes to move to next element of the array
    decq %r8            #since one element has been used we decreases the size to be processes

    cmpq $0,%r8         #if the size of the array is just one then max will be the only element hence return it as the max for further computing to get minimum and then subtarct it 
    je .reset           
    jne .loop           #if size of array is greater than 1 then move in a loop traversing each element

.error:                 #function for returning -1 as the answer in case of size of array is less than 1
    movq $-1,%rax
    ret


.loop:
    movq (%r9),%rdx             #storing the first element of the array
    addq $8,%r9                 #incrementing sie pointer to point to next element

    cmpq %rax,%rdx              #comparing the element with max of the array 
    jle .next                   #if current element is less than max then move next

    movq %rdx,%rax              #modify then max in case current element is greater than max

.next:                        #a basic function to decrease the size of the array and then chek if the size is positive repeat the loop otherwise proceed further for calculating minimum of the array
    decq %r8
    jnz .loop
    jz .reset

.reset:                 #a function to reset the local values of address pointer for first element of the array and the size of the array

    movq %rdi,%r9       #basic commands to set %r9 as address for the first element and %r8 as the size of the array
    movq %rsi,%r8       
    jmp .min            #not necessary since min is just after it 

#next 3 block of codes implement the same thing as for max just comparison commands differ for checking if current element is less than the minimum of the array
.min:
    movq (%r9),%r10         
    addq $8,%r9
    decq %r8

    cmpq $0,%r8
    je .done

.min_loop:
    movq (%r9),%rdx
    addq $8,%r9

    cmpq %r10,%rdx
    jge .min_next

    movq %rdx,%r10

.min_next:
    decq %r8
    jnz .min_loop
    jz .done
.done:
    subq %r10,%rax          #finally calculating the difference between max and min
    ret                     #since return value if by default %rax therefore res(%rax)=max(%rax)-min(%r10)
