#ifndef __CPU_H__
#define __CPU_H__

#include <stdint.h>

#include "atari2600_conf.h"

/*
 * @brief CPU instruction handler
 */ 
typedef (void)(*cpu_instruction_handler_t)();

/*
 * @brief An enum containing the CPU flags with their respective bitmask values
 */
typedef enum {
    CPU_FLAG_CARRY = 1 << 0,
    CPU_FLAG_ZERO = 1 << 1,
    CPU_FLAG_INTERRUPT = 1 << 2,
    CPU_FLAG_DECIMAL = 1 << 3,
    CPU_FLAG_BREAK = 1 << 4,
    CPU_FLAG_UNUSED = 1 << 5,
    CPU_FLAG_OVERFLOW = 1 << 6,
    CPU_FLAG_NEGATIVE = 1 << 7
} cpu_flag_t;

/*
 * @brief CPU instruction
 *
 * @param handler The instruction handler
 * @param cycles The number of cycles the instruction takes to execute
 */
typedef struct {
    cpu_instruction_handler_t handler;
    uint8_t cycles;
} cpu_instruction_t;

/*
 * @brief CPU state
 *
 * @param pc The program counter
 * @param sp The stack pointer
 * @param a The accumulator
 * @param x The x register
 * @param y The y register
 * @param flags The CPU flags
 */
typedef struct {
    uint16_t pc;
    uint8_t sp;
    uint8_t a;
    uint8_t x;
    uint8_t y;
    uint8_t flags;
} cpu_t;

#ifdef ATARI2600_CONF_CPU_ENABLE

/*
 * @brief Initialize the CPU
 */
void cpu_init();

/*
 * @brief Reset the CPU
 */
void cpu_reset();

/*
 * @brief Step the CPU
 */
void cpu_step();

/*
 * @brief Fetch an immediate value
 *
 * @return The immediate value
 */
uint8_t cpu_fetch_imm();

/*
 * @brief Fetch an absolute value
 *
 * @return The absolute value
 */
uint16_t cpu_fetch_abs();

/*
 * @brief Fetch an absolute value with the x register
 *
 * @return The absolute value with the x register
 */
uint16_t cpu_fetch_absx();

/*
 * @brief Fetch an absolute value with the y register
 *
 * @return The absolute value with the y register
 */
uint16_t cpu_fetch_absy();

/*
 * @brief Fetch a zero page value
 *
 * @return The zero page value
 */
uint8_t cpu_fetch_zp();

/*
 * @brief Fetch a zero page value with the x register
 *
 * @return The zero page value with the x register
 */
uint8_t cpu_fetch_zpx();

/*
 * @brief Fetch a zero page value with the y register
 *
 * @return The zero page value with the y register
 */
uint8_t cpu_fetch_zpy();

/*
 * @brief Fetch an indexed indirect value
 *
 * @return The indexed indirect value
 */
uint16_t cpu_fetch_indx();

/*
 * @brief Fetch an indirect indexed value
 *
 * @return The indirect indexed value
 */
uint16_t cpu_fetch_indy();

/*
 * @brief Set cpu flag
 *
 * @param mask Flag mask to set
 * @param value The value of the flag
 */
uint8_t cpu_set_flag(cpu_flag_t mask, uint8_t value);


#else

#define cpu_init(cpu) (NULL)
#define cpu_reset(cpu) (NULL)
#define cpu_step(cpu) (NULL)

#endif // MODULE_CPU_ENABLE
#endif // __CPU_H__
