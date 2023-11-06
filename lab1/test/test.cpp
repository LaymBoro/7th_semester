#include <gtest/gtest.h>

int getMin(int* arr, const size_t size)
{
	int min = arr[0];

	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

int getMax(int* arr, const size_t size)
{
	int max = arr[0];

	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

double getAverage(int* arr, const size_t size)
{
    double avg;

    for (size_t i = 0; i < size; i++)
    {
        avg += arr[i];
    }
    avg /= size;
    return avg;
}
TEST(arrTest, test_min)
{
    //Arrange
    int size = 5;
    int testArr[size] = {-10, 14, 0, 155, -200};

    //Act
    int min = getMin(testArr, size);

    //Assert
    ASSERT_EQ(min, -200);
}
TEST(arrTest, test_max)
{
    //Arrange
    int size = 5;
    int testArr[size] = {-10, 14, 0, 155, -200};

    //Act
    int max = getMax(testArr, size);

    //Assert
    ASSERT_EQ(max, 155);
}
TEST(arrTest, test_avg)
{
    //Arrange
    int size = 5;
    int testArr[size] = {-10, 14, 0, 155, -200};

    //Act
    double avg = getAverage(testArr, size);

    //Assert
    ASSERT_EQ(avg, -8.2);
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}