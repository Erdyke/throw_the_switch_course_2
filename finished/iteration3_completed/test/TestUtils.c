#include "Core.h"
#include "unity.h"
#include "Utils.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_MASK_RANGE_should_ReturnProperRangesGivenValidInputs(void)
{
    uint32_t chk;

    chk = MASK_RANGE(4,5);
    TEST_ASSERT_EQUAL_HEX32(0x00000030, chk);

    chk = MASK_RANGE(4,6);
    TEST_ASSERT_EQUAL_HEX32(0x00000070, chk);

    chk = MASK_RANGE(4,4);
    TEST_ASSERT_EQUAL_HEX32(0x00000010, chk);

    chk = MASK_RANGE(0,0);
    TEST_ASSERT_EQUAL_HEX32(0x00000001, chk);

    chk = MASK_RANGE(31,31);
    TEST_ASSERT_EQUAL_HEX32(0x80000000, chk);

    chk = MASK_RANGE(1,30);
    TEST_ASSERT_EQUAL_HEX32(0x7FFFFFFE, chk);

    chk = MASK_RANGE(0,30);
    TEST_ASSERT_EQUAL_HEX32(0x7FFFFFFF, chk);

    chk = MASK_RANGE(1,31);
    TEST_ASSERT_EQUAL_HEX32(0xFFFFFFFE, chk);

    chk = MASK_RANGE(0,31);
    TEST_ASSERT_EQUAL_HEX32(0xFFFFFFFF, chk);
}

void test_MASK_BIT_PAIR_should_ProperlyCreateMasksForBits0To31(void)
{
    TEST_ASSERT_EQUAL_HEX32(0x00000003, MASK_BIT_PAIR(0,  3));
    TEST_ASSERT_EQUAL_HEX32(0x0000000C, MASK_BIT_PAIR(1,  3));
    TEST_ASSERT_EQUAL_HEX32(0x00000030, MASK_BIT_PAIR(2,  3));
    TEST_ASSERT_EQUAL_HEX32(0x000000C0, MASK_BIT_PAIR(3,  3));
    TEST_ASSERT_EQUAL_HEX32(0x00000300, MASK_BIT_PAIR(4,  3));
    TEST_ASSERT_EQUAL_HEX32(0x00000C00, MASK_BIT_PAIR(5,  3));
    TEST_ASSERT_EQUAL_HEX32(0x00003000, MASK_BIT_PAIR(6,  3));
    TEST_ASSERT_EQUAL_HEX32(0x0000C000, MASK_BIT_PAIR(7,  3));
    TEST_ASSERT_EQUAL_HEX32(0x00030000, MASK_BIT_PAIR(8,  3));
    TEST_ASSERT_EQUAL_HEX32(0x000C0000, MASK_BIT_PAIR(9,  3));
    TEST_ASSERT_EQUAL_HEX32(0x00300000, MASK_BIT_PAIR(10, 3));
    TEST_ASSERT_EQUAL_HEX32(0x00C00000, MASK_BIT_PAIR(11, 3));
    TEST_ASSERT_EQUAL_HEX32(0x03000000, MASK_BIT_PAIR(12, 3));
    TEST_ASSERT_EQUAL_HEX32(0x0C000000, MASK_BIT_PAIR(13, 3));
    TEST_ASSERT_EQUAL_HEX32(0x30000000, MASK_BIT_PAIR(14, 3));
    TEST_ASSERT_EQUAL_HEX32(0xC0000000, MASK_BIT_PAIR(15, 3));
    TEST_ASSERT_EQUAL_HEX32(0x00000003, MASK_BIT_PAIR(16, 3));
    TEST_ASSERT_EQUAL_HEX32(0x0000000C, MASK_BIT_PAIR(17, 3));
    TEST_ASSERT_EQUAL_HEX32(0x00000030, MASK_BIT_PAIR(18, 3));
    TEST_ASSERT_EQUAL_HEX32(0x000000C0, MASK_BIT_PAIR(19, 3));
    TEST_ASSERT_EQUAL_HEX32(0x00000300, MASK_BIT_PAIR(20, 3));
    TEST_ASSERT_EQUAL_HEX32(0x00000C00, MASK_BIT_PAIR(21, 3));
    TEST_ASSERT_EQUAL_HEX32(0x00003000, MASK_BIT_PAIR(22, 3));
    TEST_ASSERT_EQUAL_HEX32(0x0000C000, MASK_BIT_PAIR(23, 3));
    TEST_ASSERT_EQUAL_HEX32(0x00030000, MASK_BIT_PAIR(24, 3));
    TEST_ASSERT_EQUAL_HEX32(0x000C0000, MASK_BIT_PAIR(25, 3));
    TEST_ASSERT_EQUAL_HEX32(0x00300000, MASK_BIT_PAIR(26, 3));
    TEST_ASSERT_EQUAL_HEX32(0x00C00000, MASK_BIT_PAIR(27, 3));
    TEST_ASSERT_EQUAL_HEX32(0x03000000, MASK_BIT_PAIR(28, 3));
    TEST_ASSERT_EQUAL_HEX32(0x0C000000, MASK_BIT_PAIR(29, 3));
    TEST_ASSERT_EQUAL_HEX32(0x30000000, MASK_BIT_PAIR(30, 3));
    TEST_ASSERT_EQUAL_HEX32(0xC0000000, MASK_BIT_PAIR(31, 3));
}

void test_MASK_RANGE_PAIRS_should_ReturnProperRangesGivenValidInputs(void)
{
    //In Range 0-15
    TEST_ASSERT_EQUAL_HEX32(0x00000003, MASK_RANGE_PAIRS(0,  0,  0x3));
    TEST_ASSERT_EQUAL_HEX32(0x0000000F, MASK_RANGE_PAIRS(0,  1,  0x3));
    TEST_ASSERT_EQUAL_HEX32(0x0000003C, MASK_RANGE_PAIRS(1,  2,  0x3));
    TEST_ASSERT_EQUAL_HEX32(0x0FFFFFF0, MASK_RANGE_PAIRS(2,  13, 0x3));
    TEST_ASSERT_EQUAL_HEX32(0x30000000, MASK_RANGE_PAIRS(14, 14, 0x3));
    TEST_ASSERT_EQUAL_HEX32(0xC0000000, MASK_RANGE_PAIRS(15, 15, 0x3));
    TEST_ASSERT_EQUAL_HEX32(0xFFFFFFFF, MASK_RANGE_PAIRS(0,  15, 0x3));

    TEST_ASSERT_EQUAL_HEX32(0x00000001, MASK_RANGE_PAIRS(0,  0,  0x1));
    TEST_ASSERT_EQUAL_HEX32(0x00000005, MASK_RANGE_PAIRS(0,  1,  0x1));
    TEST_ASSERT_EQUAL_HEX32(0x00000014, MASK_RANGE_PAIRS(1,  2,  0x1));
    TEST_ASSERT_EQUAL_HEX32(0x05555550, MASK_RANGE_PAIRS(2,  13, 0x1));
    TEST_ASSERT_EQUAL_HEX32(0x10000000, MASK_RANGE_PAIRS(14, 14, 0x1));
    TEST_ASSERT_EQUAL_HEX32(0x40000000, MASK_RANGE_PAIRS(15, 15, 0x1));
    TEST_ASSERT_EQUAL_HEX32(0x55555555, MASK_RANGE_PAIRS(0,  15, 0x1));

    TEST_ASSERT_EQUAL_HEX32(0x00000002, MASK_RANGE_PAIRS(0,  0,  0x2));
    TEST_ASSERT_EQUAL_HEX32(0x0000000A, MASK_RANGE_PAIRS(0,  1,  0x2));
    TEST_ASSERT_EQUAL_HEX32(0x00000028, MASK_RANGE_PAIRS(1,  2,  0x2));
    TEST_ASSERT_EQUAL_HEX32(0x0AAAAAA0, MASK_RANGE_PAIRS(2,  13, 0x2));
    TEST_ASSERT_EQUAL_HEX32(0x20000000, MASK_RANGE_PAIRS(14, 14, 0x2));
    TEST_ASSERT_EQUAL_HEX32(0x80000000, MASK_RANGE_PAIRS(15, 15, 0x2));
    TEST_ASSERT_EQUAL_HEX32(0xAAAAAAAA, MASK_RANGE_PAIRS(0,  15, 0x2));

    //In Range 16-31
    TEST_ASSERT_EQUAL_HEX32(0x00000003, MASK_RANGE_PAIRS(16, 16, 0x3));
    TEST_ASSERT_EQUAL_HEX32(0x0000000F, MASK_RANGE_PAIRS(16, 17, 0x3));
    TEST_ASSERT_EQUAL_HEX32(0x0000003C, MASK_RANGE_PAIRS(17, 18, 0x3));
    TEST_ASSERT_EQUAL_HEX32(0x0FFFFFF0, MASK_RANGE_PAIRS(18, 29, 0x3));
    TEST_ASSERT_EQUAL_HEX32(0x30000000, MASK_RANGE_PAIRS(30, 30, 0x3));
    TEST_ASSERT_EQUAL_HEX32(0xC0000000, MASK_RANGE_PAIRS(31, 31, 0x3));
    TEST_ASSERT_EQUAL_HEX32(0xFFFFFFFF, MASK_RANGE_PAIRS(16, 31, 0x3));

    TEST_ASSERT_EQUAL_HEX32(0x00000001, MASK_RANGE_PAIRS(16, 16, 0x1));
    TEST_ASSERT_EQUAL_HEX32(0x00000005, MASK_RANGE_PAIRS(16, 17, 0x1));
    TEST_ASSERT_EQUAL_HEX32(0x00000014, MASK_RANGE_PAIRS(17, 18, 0x1));
    TEST_ASSERT_EQUAL_HEX32(0x05555550, MASK_RANGE_PAIRS(18, 29, 0x1));
    TEST_ASSERT_EQUAL_HEX32(0x10000000, MASK_RANGE_PAIRS(30, 30, 0x1));
    TEST_ASSERT_EQUAL_HEX32(0x40000000, MASK_RANGE_PAIRS(31, 31, 0x1));
    TEST_ASSERT_EQUAL_HEX32(0x55555555, MASK_RANGE_PAIRS(16, 31, 0x1));

    TEST_ASSERT_EQUAL_HEX32(0x00000002, MASK_RANGE_PAIRS(16, 16, 0x2));
    TEST_ASSERT_EQUAL_HEX32(0x0000000A, MASK_RANGE_PAIRS(16, 17, 0x2));
    TEST_ASSERT_EQUAL_HEX32(0x00000028, MASK_RANGE_PAIRS(17, 18, 0x2));
    TEST_ASSERT_EQUAL_HEX32(0x0AAAAAA0, MASK_RANGE_PAIRS(18, 29, 0x2));
    TEST_ASSERT_EQUAL_HEX32(0x20000000, MASK_RANGE_PAIRS(30, 30, 0x2));
    TEST_ASSERT_EQUAL_HEX32(0x80000000, MASK_RANGE_PAIRS(31, 31, 0x2));
    TEST_ASSERT_EQUAL_HEX32(0xAAAAAAAA, MASK_RANGE_PAIRS(16, 31, 0x2));
}

void test_COUNT_HIGH_BITS8_should_ProperlyCountHighBitsInAByte(void)
{
    TEST_ASSERT_EQUAL_INT8(0, COUNT_HIGH_BITS8(0x00));

    TEST_ASSERT_EQUAL_INT8(1, COUNT_HIGH_BITS8(0x01));
    TEST_ASSERT_EQUAL_INT8(1, COUNT_HIGH_BITS8(0x02));
    TEST_ASSERT_EQUAL_INT8(1, COUNT_HIGH_BITS8(0x10));
    TEST_ASSERT_EQUAL_INT8(1, COUNT_HIGH_BITS8(0x80));

    TEST_ASSERT_EQUAL_INT8(2, COUNT_HIGH_BITS8(0x03));
    TEST_ASSERT_EQUAL_INT8(2, COUNT_HIGH_BITS8(0xC0));
    TEST_ASSERT_EQUAL_INT8(2, COUNT_HIGH_BITS8(0x81));

    TEST_ASSERT_EQUAL_INT8(3, COUNT_HIGH_BITS8(0x07));
    TEST_ASSERT_EQUAL_INT8(3, COUNT_HIGH_BITS8(0xE0));
    TEST_ASSERT_EQUAL_INT8(3, COUNT_HIGH_BITS8(0x51));

    TEST_ASSERT_EQUAL_INT8(4, COUNT_HIGH_BITS8(0x0F));
    TEST_ASSERT_EQUAL_INT8(4, COUNT_HIGH_BITS8(0xF0));
    TEST_ASSERT_EQUAL_INT8(4, COUNT_HIGH_BITS8(0xAA));
    TEST_ASSERT_EQUAL_INT8(4, COUNT_HIGH_BITS8(0x55));

    TEST_ASSERT_EQUAL_INT8(5, COUNT_HIGH_BITS8(0x1F));
    TEST_ASSERT_EQUAL_INT8(5, COUNT_HIGH_BITS8(0xF8));
    TEST_ASSERT_EQUAL_INT8(5, COUNT_HIGH_BITS8(0x5E));

    TEST_ASSERT_EQUAL_INT8(6, COUNT_HIGH_BITS8(0x3F));
    TEST_ASSERT_EQUAL_INT8(6, COUNT_HIGH_BITS8(0xFC));
    TEST_ASSERT_EQUAL_INT8(6, COUNT_HIGH_BITS8(0xEE));

    TEST_ASSERT_EQUAL_INT8(7, COUNT_HIGH_BITS8(0xFE));
    TEST_ASSERT_EQUAL_INT8(7, COUNT_HIGH_BITS8(0x7F));
    TEST_ASSERT_EQUAL_INT8(7, COUNT_HIGH_BITS8(0xF7));

    TEST_ASSERT_EQUAL_INT8(8, COUNT_HIGH_BITS8(0xFF));
}

