#include <iostream>
#include <vector>
#include <stdexcept>
#include "vectors.hpp"
using namespace std;

class Matrix
{
private:
    vector<vector<int>> data;
    int rows;
    int columns;

public:
    Matrix(const vector<vector<int>> matrix_data)
    {
        if (matrix_data.size() == 0 || matrix_data[0].size() == 0)
        {
            throw invalid_argument("matrix should have atleast one element to be initialized!");
        }

        rows = matrix_data.size();
        columns = matrix_data[0].size();
        data = matrix_data;
    };

    /// @brief takeColumn function would provide this column of the matrix
    /// @param col represent the column of this matrix
    /// @return is a vector in integers that represent the elements of the column
    vector<int> takeColumn(int col)
    {
        vector<int> column;
        for (int i = 0; i < rows; i++)
        {
            column.push_back(data[i][col]);
        }
        return column;
    }

    /// @brief Multiplies teh matrix with a scalar
    /// @param scalar the scalar with which the matrix would be multiplied
    void scalarMultiplication(int scalar)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                data[i][j] *= scalar;
            }
        }
    }

    /// @brief Does the matrix multiplication by using the concept of representing the process as a linear combination of columns of matrices
    /// @param left represents the left matrix that would be multiplied
    Matrix linearCombinationMultiplication(Matrix left)
    {
        if (columns != left.rows)
        {
            throw invalid_argument("invalid dimension provided for the matrix multiplication");
        }
        vector<vector<int>> result_matrix(rows, vector<int>(left.columns, INT_MIN));
        Matrix result(result_matrix);
        int result_columns = result.columns;

        for (int result_col = 0; result_col < result_columns; result_col++)
        {
            vector<vector<int>> linear_columns;
            for (int col = 0; col < columns; col++)
            {
                /// Extract this column of the matrix
                auto current_column = takeColumn(col);
                int scalar = left.data[col][result_col];
                vectorScalarMultiplication(scalar, current_column);
                linear_columns.push_back(current_column);
            }

            // This the the column of the result matrix
            vector<int> result_column = vectorAddition(linear_columns);
            for (int i = 0; i < result.rows; i++)
            {
                result.data[i][result_col] = result_column[i];
            }
        }

        return result;
    }
};
