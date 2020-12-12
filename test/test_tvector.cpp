#include "utmatrix.h"

#include <gtest.h>


TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, can_create_vector_with_max_size)
{
	ASSERT_NO_THROW(TVector<int> v(MAX_VECTOR_SIZE));
}

TEST(TVector, can_create_vector_with_zero_size)
{
	ASSERT_NO_THROW(TVector<int> v(0));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
	ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> v(10);

	ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int>A1(9);
	TVector<int>A2(A1);
	EXPECT_EQ(A1, A2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int>A1(9);
	TVector<int>A2(A1);
	EXPECT_NE(A1.GetVector(), A2.GetVector());
}

TEST(TVector, can_get_size)
{
	TVector<int> vector(3);

	EXPECT_EQ(3, vector.GetSize());
}

TEST(TVector, can_get_start_index)
{
	TVector<int> vector(9, 3);

	EXPECT_EQ(3, vector.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> vector(9);
	vector[0] = 228;

	EXPECT_EQ(228, vector[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> vector(3);


	ASSERT_ANY_THROW(vector[-1]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> vector(3);

	ASSERT_ANY_THROW(vector[12]);

}
//
TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> vector(15);
	ASSERT_NO_THROW(vector = vector);
}
//
TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> vector1(4);
	TVector<int>vector2(4);
	auto i = vector2.GetVector();
	vector2 = vector1;
	EXPECT_EQ(i, v2.GetVector());
}

TEST(TVector, assign_operator_change_vector_size)
{

	TVector<int> vector1(4);
	TVector<int>vector2(6);
	vector1 = vector2;
	EXPECT_EQ(vector2.GetSize(), 4);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> vector1(4);
	TVector<int>vector2(6);
	ASSERT_NO_THROW(vector1 = vector2);

}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(4);
	TVector<int>v1(4);
	EXPECT_EQ(v1 == v, 1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(4);
	EXPECT_EQ(v == v, 1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(4);
	TVector<int>v1(5);
	EXPECT_EQ(v1 == v, 0);

}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(4);
	TVector<int> v1(4);
	v = v + 4;
	for (int i = v1.GetStartIndex(); i < v1.GetSize(); i++)
	{
		v1[i] = 4;
	}
	EXPECT_EQ(v1, v);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(4);
	TVector<int> v1(4);
	v = v - 4;
	for (int i = v1.GetStartIndex(); i < v1.GetSize(); i++)
	{
		v1[i] = -4;
	}
	EXPECT_EQ(v1, v);
}
//
TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> vector1(4);
	TVector<int> vector2(4);
	vector1 = vector1 + 1;
	vector1 = vector1 * 3;
	for (int i = vector2.GetStartIndex(); i < vector2.GetSize(); i++)
	{
		vector2[i] = 3;
	}
	EXPECT_EQ(vector2, vector1);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> vector1(4);
	TVector<int> vector2(4);
	TVector<int> vector3(4);
	v1 = v1 + 4;
	v2 = v2 + 3;
	v3 = v3 + 7;

	EXPECT_EQ(v1 + v, v3);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> vector1(9);
	TVector<int> vector2(3);
	ASSERT_ANY_THROW(vector1 + vector2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> vector1(3);
	TVector<int> vector2(3);
	ASSERT_NO_THROW(vector1+ vector2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> vector1(3);
	TVector<int> vector2(2);
	ASSERT_ANY_THROW(v - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> vector1(4);
	TVector<int> vector2(4);
	ASSERT_NO_THROW(vector1 * vector2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> vector1(3);
	TVector<int> vector2(4);
	ASSERT_ANY_THROW(vector1 * vector2);
}
