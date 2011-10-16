# Part *find_part( char pid1, char pid2, uint16 pid3 );

.file "find_part.s"

.section .data

.section .text

.globl find_part
    .type find_part, @function

find_part:

# Set up the stack frame
    pushl   %ebp
    movl    %esp, %ebp

# Code here
    
    # (%ebp)    -> old ebp value
    # 4(%ebp)   -> return address
    # 8(%ebp)   -> function param #1 -> (1 byte) pid1
    # 12(%ebp)  -> function param #2 -> (1 byte) pid2
    # 16(%ebp)  -> function param #3 -> (2 bytes) pid3

    movl    parts, %edx
    
start_part_loop:
    
    test_pid1:
        movl    8(%ebp), %ebx
        movl    8(%edx), %ecx
        
        cmp     %bl, %cl

        jne     move_part_pointer

    test_pid2:
        
        movl    12(%ebp), %ebx
        movl    9(%edx), %ecx
        
        cmp     %bl, %cl

        jne     move_part_pointer

    test_pid3:
        
        movl    16(%ebp), %ebx
        movl    10(%edx), %ecx
        
        cmp     %bx, %cx

        jne     move_part_pointer

    found_part:

        movl    %edx, %eax
        jmp     done_part_loop
    
    move_part_pointer:
        
        movl    0(%edx), %ebx
        cmp     $0, %ebx

        jne     set_next_part

    return_zero_part:
        
        movl    $0, %eax
        jmp     done_part_loop

    set_next_part:

        movl    0(%edx), %edx
        jmp     start_part_loop

done_part_loop:


# End Code
    movl    %ebp, %esp
    pop     %ebp
    ret
