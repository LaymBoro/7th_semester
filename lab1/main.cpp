#include <iostream>
#include <random>

/** 
 * @brief Set num's in a array.
 * @param size Size of array.
 * @param array Dinamic array.
 */
void randomInput(int* arr, const size_t size);

/** 
 * @brief Get num's of array.
 * @param size Size of array.
 * @param array Dinamic array.
 */
void printArr(int* arr, const size_t size);

/** 
 * @brief Bubble sort.
 * @param size Size of array.
 * @param array Dinamic array.
 */
void bubbleSort(int* arr, const size_t size);

/** 
 * @brief Get min num of array.
 * @param size Size of array.
 * @param array Dinamic array.
 */
int getMin(int* arr, const size_t size);

/** 
 * @brief Get max num of array.
 * @param size Size of array.
 * @param array Dinamic array.
 */
int getMax(int* arr, const size_t size);

/** 
 * @brief Get average.
 * @param size Size of array.
 * @param array Dinamic array.
 */
double getAverage(int* arr, const size_t size);

int main()
{
	std::string inputSize;
    int size = -1;
    std::cout << "Input size: ";
    while(size < 0)
    {
        try
        {
	        std::cin >> inputSize;
            size = stoi(inputSize);
            if(size <= 0)
            {
                throw std::out_of_range("belowZeroSize");
            }
        }
        catch(std::invalid_argument)
        {
            std::cout << "only num's!\ntry again:";
        }
        catch(std::out_of_range)
        {
            std::cout << "size must be above zero!\ntry again:";
        }
    }
    
    int* arr = new int[size];
    randomInput(arr, size);

    std::cout << "unsorted array: ";
	printArr(arr, size);
	bubbleSort(arr, size);
	std::cout << "sorted array: ";
	printArr(arr, size);

	std::cout << "minimum: " << getMin(arr, size) << "\n";
    std::cout << "average: " << getAverage(arr, size) << "\n";       
	std::cout << "maximum: " << getMax(arr, size) << "\n";

	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}
    
	return 0;
}

void randomInput(int* arr, const size_t size)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> uniformIntDistribution(INT8_MIN, INT8_MAX);

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = uniformIntDistribution(gen);
	}
}

void printArr(int* arr, const size_t size)
{

    std::cout << "[" << arr[0];
	for (size_t i = 1; i < size; i++)
	{
		std::cout << ", " << arr[i];
	}
	std::cout << "]\n";
}

void bubbleSort(int* arr, const size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

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

