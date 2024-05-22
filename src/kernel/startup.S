.section .text.bootstrap

.global _start

.extern _entry

.extern _stack_end
.global _stack_end

_start:
    csrr a0, mhartid
    bnez a0, park

    la sp, _stack_end

    j _entry

1:  j 1b

park:
    wfi
    j park
