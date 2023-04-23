#include <cstdint>
#include <iostream>
using namespace std;

enum lastFlags
{
    C = 2,
    V = 3
};

uint32_t
ADD(uint32_t op1, uint32_t op2, bool *flags)
{
    signed int sop1 = op1;
    signed int sop2 = op2;
    signed int result = sop1 + sop2;
    flags[V] = (sop1 > 0 && sop2 > 0 && result < 0) || (sop1 < 0 && sop2 < 0 && result > 0);

    unsigned long carryResult = op1 + op2;
    flags[C] = UINT32_MAX > result;
    return op1 + op2;
}

uint32_t AND(uint32_t op1, uint32_t op2, bool *flags)
{
    return op1 & op2;
}

uint32_t SUB(uint32_t op1, uint32_t op2, bool *flags)
{
    flags[C] = (op1 > op2);
    signed int sop1 = op1;
    signed int sop2 = op2;
    signed int result = sop1 - sop2;

    flags[V] = !(sop1 > 0 && sop2 > 0 && result < 0) || (sop1 < 0 && sop2 < 0 && result > 0);

    return op1 - op2;
}

uint32_t ASR(uint32_t op1, uint32_t op2, bool *flags)
{
    int32_t op3 = op1;
    return op3 >> op2;
}

uint32_t LSL(uint32_t op1, uint32_t op2, bool *flags)
{
    return op1 << op2;
}

uint32_t LSR(uint32_t op1, uint32_t op2, bool *flags)
{
    return op1 >> op2;
}

uint32_t NOT(uint32_t op1, uint32_t op2, bool *flags)
{
    return ~op1;
}
uint32_t ORR(uint32_t op1, uint32_t op2, bool *flags)
{
    return op1 | op2;
}
uint32_t XOR(uint32_t op1, uint32_t op2, bool *flags)
{
    return op1 ^ op2;
}

uint32_t MOV(uint32_t op1, uint32_t op2, bool *flags)
{
    return op1;
}