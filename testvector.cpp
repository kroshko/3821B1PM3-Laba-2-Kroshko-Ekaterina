#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
	TDynamicVector<int> v(10);

	ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> v2(3);
	{
		TDynamicVector<int> v1(10);
		v2 = v1;
	}
	EXPECT_NO_FATAL_FAILURE(v2[1] = 3);
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> v1(10), v2(5);
	for (size_t i = 0; i < v1.size(); i++)
		v1[i] = i + 4;
	v2 = v1;
	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, can_get_size)
{
	TDynamicVector<int> v(4);

	EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(4);
	EXPECT_ANY_THROW(v.at(-1) = 3);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(4);
	EXPECT_ANY_THROW(v.at(4) = 3);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(4);
	for (size_t i = 0; i < v.size(); i++)
		v[i] = i + 4;
	v = v;
	EXPECT_NO_FATAL_FAILURE(v[1] = 3);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> v1(4), v2(4);
	for (size_t i = 0; i < v1.size(); i++)
		v1[i] = i + 4;
	v2 = v1;
	EXPECT_EQ(4, v2[0]);
	EXPECT_EQ(7, v2[3]);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int>t1(3);
	TDynamicVector<int>t2(5);
	int previous_size = t1.size();
	t1 = t2;
	int new_size = t1.size();
	EXPECT_NE(previous_size, new_size);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int>v1(3);
	TDynamicVector<int>v2(5);
	ASSERT_NO_THROW(v1 = v2);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int>v1(3);
	TDynamicVector<int>v2(3);
	for (int i = 0; i < 3; i++) {
		v1[i] = i + 1;
		v2[i] = i + 1;
	}
	EXPECT_EQ(true, v1 == v2);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int>v1(3);
	EXPECT_EQ(true, v1 == v1);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int>v1(3);
	TDynamicVector<int>v2(4);
	EXPECT_EQ(true, v1 != v2);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int>v1(3);
	for (int i = 0; i < 3; i++) {
		v1[i] = i;
	}
	TDynamicVector<int>v2 = v1 + 5;
	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(v1[i] + 5, v2[i]);
	}
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int>v1(3);
	for (int i = 0; i < 3; i++) {
		v1[i] = i;
	}
	TDynamicVector<int>v2 = v1 - 5;
	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(v1[i] - 5, v2[i]);
	}
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int>v1(3);
	for (int i = 0; i < 3; i++) {
		v1[i] = i;
	}
	TDynamicVector<int>v2 = v1 * 5;
	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(v1[i] * 5, v2[i]);
	}
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int>v1(3);
	TDynamicVector<int>v2(3);
	for (int i = 0; i < 3; i++) {
		v1[i] = i;
		v2[i] = i + 2;
	}
	TDynamicVector<int>v3 = v1 + v2;
	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(v1[i] + v2[i], v3[i]);
	}
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int>v1(3);
	TDynamicVector<int>v2(4);
	ASSERT_ANY_THROW(TDynamicVector<int>v3 = v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int>v1(3);
	TDynamicVector<int>v2(3);
	for (int i = 0; i < 3; i++) {
		v1[i] = i;
		v2[i] = i + 2;
	}
	TDynamicVector<int>v3 = v1 - v2;
	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(v1[i] - v2[i], v3[i]);
	}
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int>v1(3);
	TDynamicVector<int>v2(4);
	ASSERT_ANY_THROW(TDynamicVector<int>v3 = v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int>v1(3);
	TDynamicVector<int>v2(3);
	int anss = 0;
	for (int i = 0; i < 3; i++) {
		v1[i] = i;
		v2[i] = i + 2;
		anss += v1[i] * v2[i];
	}
	int ans = v1 * v2;
	EXPECT_EQ(anss, ans);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int>v1(3);
	TDynamicVector<int>v2(4);
	ASSERT_ANY_THROW(int ans = v1 * v2);
}