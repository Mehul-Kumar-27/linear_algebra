#include <iostream>
#include <vector>
using namespace std;

/// @brief Multiplies teh matrix with a scalar
/// @param matrix
/// @param scalar
void scalarMultiplication(vector<vector<int>> &matrix, int scalar)
{
    int rows = matrix.size();
    int columns = matrix[1].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] *= scalar;
        }
    }
}

/// @brief  This function is going to take in two matrixes and multiply them
/// @param m1 represents the matrix that is going to be on the left hand side
/// @param m2 represents the matrix that is going to be on the right hand side
/// @return is a vector<int> type which would contain the solution matrix
vector<vector<int>> simpleMultiply(vector<vector<int>> m1, vector<vector<int>> m2)
{
    /// Check if we can multiply the two matrixes
    if (m1[0].size() != m2.size())
    {
        /// We cannot multiply the two matrixes
        throw invalid_argument("Matrixes dimensions do not match for multiplication");
    }

    vector<vector<int>> solution;
}
