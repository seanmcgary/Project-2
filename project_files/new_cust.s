# Customer *new_cust( char *name, char cid1, uint16 cid2, uint16 limit );
.file   "new_cust.s"
.section .data

.section .text

.globl new_cust
    .type new_cust, @function

new_cust:
    
    pushl   %ebp        # save the callers stack
    movl    %esp, %ebp  # set the ebp to where the esp is (bottom of last stack frame)
# Code here

# (%ebp) -> old ebp value
# 4(%ebp) -> return address
# 8(%ebp) -> function param #1 -> name pointer
# 12(%ebp) -> function param #2 -> cid1 character
# 16(%ebp) -> function param #3 -> cid2 2 byte int
# 20(%ebp) -> function param #4 -> limit 2 byte int
    
    pushl   $20
    call    allocate 
    addl    $20, %esp

    # name - 8
    movl    8(%ebp), %edx
    movl    %edx, 8(%eax)
    
    # cid1 - 18
    movl    12(%ebp), %edx
    movb    %dl, 18(%eax)   # since its only a byte, move the contents from the lob  
    
    # cid2 - 16
    movl    16(%ebp), %edx
    movw    %dx, 16(%eax)   # only 2 bytes, so use the lower 16 bits
    
    # limit - 12
    movl    20(%ebp), %edx
    movw    %dx, 12(%eax)   # only 2 bytes, so use the lower 16 bits

    movw    $5000, 14(%eax)
    
# End Code
    movl    %ebp, %esp  # restore the stack 
    pop     %ebp        # restore the frame
    ret                 # return to the calling routine
