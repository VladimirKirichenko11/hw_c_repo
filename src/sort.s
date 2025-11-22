.globl sort_array

sort_array:
    
    push %rbx
    push %rsi
    push %rdi
    
    mov %rcx, %rdi
    mov %edx, %esi
    
    # Если размер <= 1, сразу выходим
    cmp $1, %esi
    jle no_sort
    
    mov $0, %r10d # moved_count = 0
    
    # Внешний цикл: i = size-1 down to 1
    mov %esi, %ecx
    dec %ecx # ecx = i
    
outer_loop:
    mov $0, %r8d # j = 0
    mov $0, %r9d # swapped = 0
    
inner_loop:
    # Загружаем array[j] и array[j+1]
    mov (%rdi, %r8, 4), %eax # eax = array[j]
    mov 4(%rdi, %r8, 4), %ebx # ebx = array[j+1]
    
    # Сравниваем
    cmp %ebx, %eax
    jle no_swap
    
    mov %ebx, (%rdi, %r8, 4)    # array[j] = array[j+1]
    mov %eax, 4(%rdi, %r8, 4)   # array[j+1] = array[j]
    
    inc %r10d         # moved_count++
    mov $1, %r9d      # swapped = 1
    
no_swap:
    inc %r8d          # j++
    cmp %ecx, %r8d    # j < i?
    jl inner_loop
    
    # Проверяем, были ли обмены
    cmp $0, %r9d
    je sort_done      # если не было обменов - выходим
    
    dec %ecx          # i--
    jnz outer_loop    # если i > 0, продолжаем

sort_done:
    mov %r10d, %eax   # возвращаем moved_count
    jmp cleanup

no_sort:
    mov $0, %eax      # возвращаем 0

cleanup:
    pop %rdi
    pop %rsi
    pop %rbx
    ret
