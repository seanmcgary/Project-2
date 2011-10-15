# Part *new_part( char pid1, char pid2, uint16 pid3, uint8 avail, 
#                 uint16 price1, uint8 price2 );

.file "new_part.s"

.section .data

.section .text

.globl  new_part
    .type new_part, @function

new_part:
# Set up the stack frame
    pushl   %ebp
    movl    %esp, %ebp
    
# Code here

    # (%ebp)    -> old ebp value
    # 4(%ebp)   -> return address
    # 8(%ebp)   -> function param #1 -> (1 byte) char pid1
    # 12(%ebp)  -> function param #2 -> (1 byte) char pid2
    # 16(%ebp)  -> function param #3 -> (2 bytes) int pid3
    # 20(%ebp)  -> function param #4 -> (1 byte) int available 
    # 24(%ebp)  -> function param #5 -> (2 bytes) int price1
    # 28(%ebp)  -> function param #6 -> (1 byte) int price2
    
    pushl   $16
    call    allocate
    addl    $16, %esp
    
    # pid1
    movl    8(%ebp), %edx
    movb    %dl, 8(%eax)

    # pid2
    movl    12(%ebp), %edx
    movb    %dl, 9(%eax)

    # pid3
    movl    16(%ebp), %edx
    movw    %dx, 10(%eax)

    # available
    movl    20(%ebp), %edx
    movb    %dl, 15(%eax)

    # price1
    movl    24(%ebp), %edx
    movw    %dx, 12(%eax)

    # price2
    movl    28(%ebp), %edx
    movb    %dl, 14(%eax)

# End Code
    movl    %ebp, %esp
    pop     %ebp
    ret
