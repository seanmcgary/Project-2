# Customer *find_cust( char cid1, uint16 cid2 );

.file   "find_cust.s"

.section .data

.section .text

.globl find_cust
    .type find_cust, @function

find_cust:

# Set up the stack frame
    pushl   %ebp
    movl    %esp, %ebp
# Code here
    # (%ebp) -> old ebp value
    # 4(%ebp) -> return address
    # 8(%ebp) -> function param #1 -> (1 byte) cid1
    # 12(%ebp) -> function param #2 -> (2 bytes) cid2
    
    # load the global customers pointer 
    movl    customers, %edx

    # 18(%edx) -> cid1 character
    # 16(%ebp) -> cid2 2 byte int
start_loop:

    test_cid1:
        # compare
        movl    8(%ebp), %ebx       # cid1 from arguments
        movl    18(%edx), %ecx      # cid1 from current customer

        cmp     %bl, %cl            # compare

        jne     move_pointer        # if they arent equal, move on to
                                    # selecting the next customer
    
    test_cid2:

        movl    12(%ebp), %ebx
        movl    16(%edx), %ecx

        cmp     %bx, %cx

        jne     move_pointer 

    found_cust:
        # if we fall into this label, both cid1 and cid2 are matches
        # move the current customer in %edx to %eax and jumpt to done_loop
        movl    %edx, %eax
        jmp     done_loop

    move_pointer:
        # if we make it here, then the current customer is not a match.
        # set the %edx register to the pointer to the next customer in the 
        # list if next is not 0
        
        # get the next pointer at 0(%edx)
        movl    0(%edx), %ebx
        cmp     $0, %ebx    # check if its zero

        jne     set_next_cust

    return_zero:
        
        movl    $0, %eax
        jmp     done_loop

    set_next_cust:
        
        movl    0(%edx), %edx
        jmp     start_loop

done_loop:
    # found the customer, return the pointer in %eax
# End Code
    movl    %ebp, %esp
    pop     %ebp
    ret
