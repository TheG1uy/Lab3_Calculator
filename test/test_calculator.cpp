#include "Calculator.h"
#include "Calculator.cpp"
#include <gtest.h>

TEST(TCalculate, get_no_throw_when_try_transform_infix_in_postfix)
{
	TCalculator a;
	a.setInfix("3+2");
	ASSERT_NO_THROW(a.GoToPostfix());
}
TEST(TCalculate, can_add_elem_to_elem)
{
	TCalculator a;
	a.setInfix("2+3");
	a.GoToPostfix();
	EXPECT_EQ(5, a.GoToCalculate());
}
TEST(TCalculate, can_deduct_elem_of_elem)
{
	TCalculator a;
	a.setInfix("2-3");
	a.GoToPostfix();
	EXPECT_EQ(-1, a.GoToCalculate());
}

TEST(TCalculate, can_multiply_elem_no_elem)
{
	TCalculator a;
	a.setInfix("2*3");
	a.GoToPostfix();
	EXPECT_EQ(6, a.GoToCalculate());
}
TEST(TCalculate, can_divide_elem_on_elem)
{
	TCalculator a;
	a.setInfix("15/3");
	a.GoToPostfix();
	EXPECT_EQ(5, a.GoToCalculate());
}
TEST(TCalculate, can_elevate_elem)
{
	TCalculator a;
	a.setInfix("2^3");
	a.GoToPostfix();

	EXPECT_EQ(8, (float)a.GoToCalculate());
}
TEST(TCalculate, can_elevate_elem_and_add_it_to_another)
{
	TCalculator a;
	a.setInfix("2^3+10");
	a.GoToPostfix();
	EXPECT_EQ(18, a.GoToCalculate());
}
TEST(TCalculate, can_use_brackets)
{
	TCalculator a;
	a.setInfix("(2+3)*2");
	a.GoToPostfix();
	EXPECT_EQ(10, a.GoToCalculate());
}
TEST(TCalculate, can_count_large_expression)
{
	TCalculator a;
	a.setInfix("(2+3)*2-3^2+3!");
	a.GoToPostfix();
	EXPECT_EQ(7, (float)a.GoToCalculate());
}
TEST(TCalculate, can_add_int_to_double)
{
	TCalculator a;
	a.setInfix("2.2+2");
	a.GoToPostfix();
	EXPECT_EQ(4.2, a.GoToCalculate());
}TEST(TCalculate, can_add_double_to_double)
{
	TCalculator a;
	a.setInfix("2.2+2.7");
	a.GoToPostfix();
	EXPECT_EQ(4.9, a.GoToCalculate());
}
TEST(TCalculate, can_multiply_int_with_double)
{
	TCalculator a;
	a.setInfix("2.2*5");
	a.GoToPostfix();
	EXPECT_EQ(11, a.GoToCalculate());
}
TEST(TCalculate, can_multiply_double_with_double)
{
	TCalculator a;
	a.setInfix("2.2*2.5");
	a.GoToPostfix();
	EXPECT_EQ(5.5, a.GoToCalculate());
}
TEST(TCalculate, cant_introduce_wrong_string_exp_1)
{
	TCalculator a;
	a.setInfix("2.2-+2");
	EXPECT_EQ(false, a.GoToPostfix());
}
TEST(TCalculate, cant_introduce_wrong_string_exp_2)
{
	TCalculator a;
	a.setInfix("2.2-/2--2");
	EXPECT_EQ(false, a.GoToPostfix());
}
TEST(TCalculate, cant_introduce_wrong_string_exp_3)
{
	TCalculator a;
	a.setInfix("(2.2-2-))2");
	EXPECT_EQ(false, a.GoToPostfix());
}
TEST(TCalculate, can_introduce_well_string)
{
	TCalculator a;
	a.setInfix("2.2+2-2+1");
	EXPECT_EQ(true, a.GoToPostfix());
}