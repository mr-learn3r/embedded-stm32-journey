### Terminal 2 — GDB Session
Open a new terminal and run:
cd ~/embedded-stm32-journey/week0-setup/blinky
gdb-multiarch blinky.elf
What you should see:
Reading symbols from blinky.elf...
(gdb)

## Step-by-Step GDB Commands

Step 1 — Connect GDB to OpenOCD:
(gdb) target remote localhost:3333
Expected: CPU is running, paused mid-execution inside delay()

Step 2 — Reset and halt the CPU:
(gdb) monitor reset halt
Expected: [stm32f0x.cpu] halted due to debug-request

Step 3 — Set breakpoint just before LED turns OFF:
(gdb) break main.c:27
(gdb) continue
Expected: Breakpoint hits at GPIOC_ODR and= ~(1U <<6) line

Step 4 — Read ODR register BEFORE the line executes:
(gdb) x/1xw 0x48000814
Expected: 0x48000814: 0x00000040  (bit 6 SET, LED ON)

Step 5 — Step over the line and read again:
(gdb) next
(gdb) x/1xw 0x48000814
Expected: 0x48000814: 0x00000000  (bit 6 CLEARED, LED OFF)

## Results

| State                   | Address     | Value      | Binary    | LED |
|-------------------------|-------------|------------|-----------|-----|
| Before and= ~(1U << 6) | 0x48000814  | 0x00000040 | 0100 0000 | ON  |
| After  and= ~(1U << 6) | 0x48000814  | 0x00000000 | 0000 0000 | OFF |

## What This Proves
- GPIOC_ODR is at address 0x48000814 (base 0x48000800 + offset 0x14)
- Bit 6 correctly controls PC6 physical pin
- A single C instruction clears exactly bit 6
- RM0091 register map matches actual hardware behavior

## Ending the Session
(gdb) quit       <- Terminal 2: exit GDB
Ctrl+C           <- Terminal 1: stop OpenOCD

## Key Takeaway
GDB + OpenOCD lets you pause a running MCU and read any memory-mapped
register directly. When your UART driver is not sending, you pause and
inspect BRR/CR1 registers. Same technique, every time.
