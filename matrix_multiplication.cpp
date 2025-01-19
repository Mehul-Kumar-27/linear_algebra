#include <iostream>
#include <vector>
#include <stdexcept>
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

    for (int i = 0; i < matrix_data[0].size(); i++)
    {
      for (int j = 0; j < matrix_data.size(); j++)
      {
        data[j][i] = matrix_data[j][i];
      }
    }
    rows = data.size();
    columns = data[0].size();
  };
  /// @brief Multiplies teh matrix with a scalar
  /// @param scalar the scalar with which the matrix would be multiplied
  void scalarMultiplication(int scalar)
  {
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; i < columns; i++)
      {
        data[i][j] *= scalar;
      }
    }
  }
};
