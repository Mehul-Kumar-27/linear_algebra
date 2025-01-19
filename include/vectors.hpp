#include <iostream>
#include <vector>

using namespace std;

void vectorScalarMultiplication(int scalar, vector<int> &vec)
{
    if (vec.size() == 0)
    {
        throw("vector has not been initialized and has size 0 for scalar multiplication!");
    }
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] *= scalar;
    }
}

vector<int> vectorAddition(vector<vector<int>> vec_list)
{
    int data_set_size = vec_list.size();
    if (data_set_size == 0)
    {
        throw("vector list should contain atleast one vector to add!");
    }

    vector<int> vec_added_data = vec_list[0];
    int size = vec_added_data.size();
    for (int i = 1; i < vec_list.size(); i++)
    {
        if (vec_list[i].size() != size)
        {
            throw("invalid size of the vector provided for vector addition");
        }
    }
    // First add these all the vec_list
    for (int i = 1; i < data_set_size; i++)
    {
        vector<int> data_set = vec_list[i];
        for (int i = 0; i < size; i++)
        {
            vec_added_data[i] += data_set[i];
        }
    }

    return vec_added_data;
}
