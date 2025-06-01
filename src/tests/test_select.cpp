#include <gtest/gtest.h>
#include "Sorter.h"
#include "SortData.h"

TEST(test_select, SortFunction)
{
    Sorter* sorter = new Sorter();

    // Wybór kontenera: std::vector lub std::list
#if 0
    SortData<float, std::list> data;
#else
    SortData<float, std::vector> data;
#endif

    // Przykładowe nieposortowane dane
    std::vector<float> unsorted_data = {5.3, 2.1, 9.7, 1.4, 5.0, 6.2};
    for (auto num : unsorted_data)
    {
        data.add(num);
    }

    // Sortowanie Selection Sort
    auto error = sorter->sort<float, std::vector, STT_SELECT>(data);

    // Sprawdzamy, czy operacja zakończyła się sukcesem
    ASSERT_EQ(error, SE_SUCCESS);

    // Sprawdzamy, czy dane są posortowane
    bool is_sorted = true;
    for (size_t i = 1; i < data.size(); ++i)
    {
        if (data[i - 1] > data[i])
        {
            is_sorted = false;
            break;
        }
    }

    ASSERT_TRUE(is_sorted) << "Selection Sort NIE działa poprawnie!";
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}