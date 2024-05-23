# Define the kernel executable
add_executable(kernel.elf
    entry.c
    startup.S
)

# Specify the target architecture and compilation flags
set(CMAKE_C_FLAGS "-march=rv32ima_zicsr -mabi=ilp32 -nostdlib -fno-builtin -mcmodel=medany -ffreestanding")
set(CMAKE_ASM_FLAGS "-march=rv32ima_zicsr -mabi=ilp32 -nostdlib -fno-builtin -mcmodel=medany -ffreestanding")

# Specify the linker script
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/src/kernel/linker.ld)
target_link_options(kernel.elf PRIVATE "-T${LINKER_SCRIPT}")

# Compiler and linker flags
target_compile_options(kernel.elf PRIVATE -Wall -Wextra)

target_link_options(kernel.elf PRIVATE -nostartfiles -nodefaultlibs)

# Add custom commands to convert kernel executable to binary and extract debug symbols
add_custom_command(TARGET kernel.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:kernel.elf> kernel.bin
    COMMAND ${CMAKE_NM} $<TARGET_FILE:kernel.elf> > kernel.map
)
