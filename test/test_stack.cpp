#include "TStack.h"

#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<double>(10));

}

TEST(TStack, cant_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(TStack<double>(-1));
}

TEST(TStack, cant_take_elem_in_empty_stack)
{
	TStack<double> a;
	a.clear();
	ASSERT_ANY_THROW(a.pop());
}
TEST(TStack, can_take_elem_in_not_empty_stack)
{
	TStack<double> a;
	a.clear();
	a.push(1);
	ASSERT_NO_THROW(a.pop());
}
TEST(TStack, cant_push_elem_in_full_stack)
{
	TStack<double> a(1);
	a.clear();
	a.push(1);
	ASSERT_ANY_THROW(a.push(1));
}
TEST(TStack, can_take_elem_in__stack)
{
	TStack<double> a;
	a.clear();
	a.push(5);

    EXPECT_EQ(5, a.pop());
}
TEST(TStack, can_check_stack_is_empty)
{
	TStack<double> a;
	a.clear();
	a.push(5);

	EXPECT_EQ(false, a.isEmpty());
}
TEST(TStack, can_check_stack_is_full)
{
	TStack<double> a(1);
	a.clear();
	a.push(5);

	EXPECT_EQ(true, a.isFull());
}


