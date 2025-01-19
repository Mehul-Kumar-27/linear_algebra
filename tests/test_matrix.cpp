#include "gtest/gtest.h"
#include "matrix.hpp"
#include <stdexcept>

TEST(MatrixTest, Constructor_ValidInput)
{
    std::vector<std::vector<int>> data = {{1, 2}, {3, 4}};
    Matrix matrix(data);
    // No exceptions should be thrown for valid input
}

TEST(MatrixTest, Constructor_InvalidInput_EmptyMatrix)
{
    std::vector<std::vector<int>> data = {};
    EXPECT_THROW(Matrix matrix(data), std::invalid_argument);
}

TEST(MatrixTest, Constructor_InvalidInput_EmptyRows)
{
    std::vector<std::vector<int>> data = {{}};
    EXPECT_THROW(Matrix matrix(data), std::invalid_argument);
}

TEST(MatrixTest, TakeColumn_ValidColumn)
{
    std::vector<std::vector<int>> data = {{1, 2}, {3, 4}, {5, 6}};
    Matrix matrix(data);
    std::vector<int> column = matrix.takeColumn(1);
    for (int i = 0; i < column.size(); i++)
    {
        std ::cout << column[i] << std::endl;
    }

    EXPECT_EQ(column, (std::vector<int>{2, 4, 6}));
}

TEST(MatrixTest, TakeColumn_InvalidColumn)
{
    std::vector<std::vector<int>> data = {{1, 2}, {3, 4}};
    Matrix matrix(data);
    EXPECT_THROW(matrix.takeColumn(3), std::out_of_range);
}

TEST(MatrixTest, ScalarMultiplication)
{
    std::vector<std::vector<int>> data = {{1, 2}, {3, 4}};
    Matrix matrix(data);
    matrix.scalarMultiplication(2);
    std::vector<std::vector<int>> expected = {{2, 4}, {6, 8}};
    EXPECT_EQ(matrix.takeColumn(0), (std::vector<int>{2, 6}));
    EXPECT_EQ(matrix.takeColumn(1), (std::vector<int>{4, 8}));
}

TEST(MatrixTest, LinearCombinationMultiplication_ValidInput)
{
    std::vector<std::vector<int>> dataA = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> dataB = {{5, 6}, {7, 8}};
    Matrix matrixA(dataA);
    Matrix matrixB(dataB);

    Matrix result = matrixA.linearCombinationMultiplication(matrixB);
    // Expected result: [[19, 22], [43, 50]]
    EXPECT_EQ(result.takeColumn(0), (std::vector<int>{19, 43}));
    EXPECT_EQ(result.takeColumn(1), (std::vector<int>{22, 50}));
}

TEST(MatrixTest, LinearCombinationMultiplication_InvalidDimensions)
{
    std::vector<std::vector<int>> dataA = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> dataB = {{5, 6}};
    Matrix matrixA(dataA);
    Matrix matrixB(dataB);
    EXPECT_THROW(matrixA.linearCombinationMultiplication(matrixB), std::invalid_argument);
}
