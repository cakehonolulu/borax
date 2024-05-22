# Define the kernel executable
add_executable(kernel
    entry.c
    startup.S
)

# Specify the target architecture and compilation flags
set(CMAKE_C_FLAGS "-march=rv32ima_zicsr -mabi=ilp32 -nostdlib -fno-builtin -mcmodel=medany -ffreestanding")
set(CMAKE_ASM_FLAGS "-march=rv32ima_zicsr -mabi=ilp32 -nostdlib -fno-builtin -mcmodel=medany -ffreestanding")

# Specify the linker script
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/src/kernel/linker.ld)
target_link_options(kernel PRIVATE "-T ${LINKER_SCRIPT}")

# Compiler and linker flags
target_compile_options(kernel PRIVATE -Wall -Wextra)

target_link_options(kernel PRIVATE -nostartfiles -nodefaultlibs)
