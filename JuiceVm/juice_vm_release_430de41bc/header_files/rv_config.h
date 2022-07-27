/*
 * Copyright (c) 2006-2021, JuiceVm Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021/04/22     Juice        the first version
 */


#ifndef RV_CONFIG_FILE_INCLUDE
#define RV_CONFIG_FILE_INCLUDE


#if (__CURRENT_COMPILE_RV_VERSION_ == 32)

#define RV32I_SUPPORT_ONLY

#elif (__CURRENT_COMPILE_RV_VERSION_ == 64)

#else
#error "__CURRENT_COMPILE_RV_VERSION_ must be compile"
#endif


#ifdef RV32I_SUPPORT_ONLY
#define RV32I_SUPPORT_ENBALE
#else
#define RV32I_SUPPORT_ENBALE         // RV64 must be contain RV32
#define RV64I_SUPPORT_ENBALE
#define RV64_MMU_ENBALE            1
// #define RV64_PMP_ENBALE            1
#endif

#if (defined(RV64_MMU_ENBALE) && (RV64_MMU_ENBALE == 1))
#define JUICEVM_MMU_ENABLE    1

#endif
#if defined(ESPIDF)

#else
#define RV_ENDLESS_LOOP_CHECK_ENBALE            1
#endif

#if defined(RV_ENDLESS_LOOP_CHECK_ENBALE) && RV_ENDLESS_LOOP_CHECK_ENBALE == 1
#define RV_ENDLESS_LOOP_CHECK_BUF_SIZE          (30)
#define RV_ENDLESS_LOOP_CHECK_EXIT_CNT          (3)
#define RV_ENDLESS_LOOP_CHECK_MD5_HASH          1
#endif

// #define RISCV_ANGEL_ONLY
// #define RV_FLOAT_SUPPORT
#define Machine_Mode_SUPPORT
#define Supervisor_Mode_SUPPORT
#define User_Mode_SUPPORT
#ifndef Machine_Mode_SUPPORT
    #error "Machine_Mode_SUPPORT must be defined"
#endif
// #define Hypervisor_Mode_SUPPORT

#define ATOMIC_Module_SUPPORT

#define RV_CPU_CSR_DEF_Vendor_ID    0
#define RV_CPU_CSR_DEF_March_ID     0
#define RV_CPU_CSR_DEF_Mimp_ID      0
#define RV_CPU_CSR_DEF_Mhart_ID     0

#define juicevm_mem_malloc(size)    malloc(size)
#define juicevm_mem_free(p)         free(p)

#if defined(ESPIDF)
#define JUICE_VM_LOG_MAX_NUM        (0)

#define JUICE_VM_INC_CHANGELOG      0

#define RAM_SIZE_KB                 (1024)
#define RAM_SIZE_MB                 (1024*RAM_SIZE_KB)
#define RAM_SIZE_GB                 (1024*RAM_SIZE_MB)

#define RV_CPU_SIM_RAM_START_ADDR   (0x80000000)
#define RV_CPU_SIM_RAM_SIZE         (8 * RAM_SIZE_MB)

#define RV_CPU_SIM_CAUSETABLE_MAX_NUM    100//MXLEN-1 bit

#define RV_CPU_SIM_PERDEV_NUM       50
#define rv_peripheral_device_add_check_dev    1
#else
#define JUICE_VM_LOG_MAX_NUM        (6000)

#define JUICE_VM_INC_CHANGELOG      0

#define RAM_SIZE_KB                 (1024)
#define RAM_SIZE_MB                 (1024*RAM_SIZE_KB)
#define RAM_SIZE_GB                 (1024*RAM_SIZE_MB)

#define RV_CPU_SIM_RAM_START_ADDR   ((_cur_rv_uint)(0x80000000))
#define RV_CPU_SIM_RAM_SIZE         ((_cur_rv_uint)(256 * RAM_SIZE_MB))

#define RV_CPU_SIM_CAUSETABLE_MAX_NUM    100//MXLEN-1 bit

#define RV_CPU_SIM_PERDEV_NUM       50
#define rv_peripheral_device_add_check_dev    1
#endif

// | MXLEN-1          MXLEN-2 | MXLEN-3       26| 25                     0 |
// |      MXL[1:0](WARL)      |       WLRL      | Extensions[25:0] (WARL)  |
// |     2                    |     MXLEN-28    |           26             |
//                  Figure 3.1: Machine ISA register (misa).



// Bit | Character | Description
// 0   |    A      |   Atomic extension
// 1   |    B      |   Tentatively reserved for Bit-Manipulation extension
// 2   |    C      |   Compressed extension
// 3   |    D      |   Double-precision floating-point extension
// 4   |    E      |   RV32E base ISA
// 5   |    F      |   Single-precision floating-point extension
// 6   |    G      |   Reserved
// 7   |    H      |   Hypervisor extension
// 8   |    I      |   RV32I/64I/128I base ISA
// 9   |    J      |   Tentatively reserved for Dynamically Translated Languages extension
// 10  |    K      |   Reserved
// 11  |    L      |   Tentatively reserved for Decimal Floating-Point extension
// 12  |    M      |   Integer Multiply/Divide extension
// 13  |    N      |   User-level interrupts supported
// 14  |    O      |   Reserved
// 15  |    P      |   Tentatively reserved for Packed-SIMD extension
// 16  |    Q      |   Quad-precision floating-point extension
// 17  |    R      |   Reserved
// 18  |    S      |   Supervisor mode implemented
// 19  |    T      |   Tentatively reserved for Transactional Memory extension
// 20  |    U      |   User mode implemented
// 21  |    V      |   Tentatively reserved for Vector extension
// 22  |    W      |   Reserved
// 23  |    X      |   Non-standard extensions present
// 24  |    Y      |   Reserved
// 25  |    Z      |   Reserved
#define RV_MISA_ATOMIC_EXT         (1<<0)
#define RV_MISA_INTEGER_EXT        (1<<8)
#define RV_MISA_UMODE_INT_EXT      (1<<13)
#define RV_MISA_SMODE_IMP_EXT      (1<<18)
#define RV_MISA_UMODE_IMP_EXT      (1<<20)

// | MXL |  XLEN  |
// | 1   |   32   |
// | 2   |   64   |
// | 3   |   128  |
#define RV_MISA_XLEN_32            (1<<(32-2))
#define RV_MISA_XLEN_64            (uint64_t)((uint64_t)(2)<<(64-2))

#define RV_XLEN_32       (32)
#define RV_XLEN_64       (64)

#if (__CURRENT_COMPILE_RV_VERSION_ == 32)

#define RV_XLEN               RV_XLEN_32
#define RV_SHIFT_OP_MASK  0x1F

#elif (__CURRENT_COMPILE_RV_VERSION_ == 64)
#define RV_XLEN               RV_XLEN_64
#define RV_SHIFT_OP_MASK  0x3F
#else
#error "__CURRENT_COMPILE_RV_VERSION_ must be compile"
#endif


// check
#ifndef RV64I_SUPPORT_ENBALE
#if(RV_XLEN == (RV_XLEN_64))
    #error "RV_XLEN can not be RV_XLEN_64 when RV64I_SUPPORT_ENBALE is not defined"
#endif
#endif

#define RV_MISA_MXL_32bit          (1)
#define RV_MISA_MXL_64bit          (2)
#define RV_MISA_MXL_128bit         (3)


#if (__CURRENT_COMPILE_RV_VERSION_ == 32)
#define RV_MISA_MXL                (RV_MISA_MXL_32bit)
#elif (__CURRENT_COMPILE_RV_VERSION_ == 64)
#define RV_MISA_MXL                (RV_MISA_MXL_64bit)
#else
#error "__CURRENT_COMPILE_RV_VERSION_ must be compile"
#endif

// #define RV_MISA_XLEN_128           ((uint128_t)(3)<<(128-2))
// check
#ifndef RV64I_SUPPORT_ENBALE
#if(RV_MISA_MXL == (RV_MISA_MXL_64bit))
    #error "RV_MISA_MXL can not be RV_MISA_MXL_64bit when RV64I_SUPPORT_ENBALE is not defined"
#endif
#endif

#ifdef RV64I_SUPPORT_ENBALE
#define RV_MISA_CSR_REGISTER_ON_64bit       ((uint64_t)(RV_MISA_XLEN_64 | RV_MISA_ATOMIC_EXT | RV_MISA_INTEGER_EXT /* | RV_MISA_UMODE_INT_EXT */ | RV_MISA_SMODE_IMP_EXT | RV_MISA_UMODE_IMP_EXT))
#endif
#define RV_MISA_CSR_REGISTER_ON_32bit       ((uint64_t)(RV_MISA_XLEN_32 | RV_MISA_ATOMIC_EXT | RV_MISA_INTEGER_EXT /* | RV_MISA_UMODE_INT_EXT */ | RV_MISA_SMODE_IMP_EXT | RV_MISA_UMODE_IMP_EXT))



#define ORIGIN_PRINTF(...)  printf(__VA_ARGS__)
#define ORIGIN_VPRINTF(...)  vprintf(__VA_ARGS__)

#endif // RV_CONFIG_FILE_INCLUDE
