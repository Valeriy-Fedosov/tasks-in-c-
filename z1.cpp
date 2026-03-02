#include <iostream>
#include <vector>

using namespace std;

int*** init_matrix(int*** matrix, int size_on_x, int size_on_y, int size_on_z);
int*** spiral(int*** matrix, int size_on_x, int size_on_y, int size_on_z, int z);

int main()
{
    int*** matrix = NULL;

    int l, m, n;
    int z;

    vector<vector <int>> vector_3;

    cout << "input l ";
    cin >> l;
    cout << "input m ";
    cin >> m;
    cout << "input n ";
    cin >> n;

    cout << "input 1 < z < 10 ";
    cin >> z;

    matrix = init_matrix(matrix, l, m, n);
    spiral(matrix, l, m, n, z);

    return 0;
}

int*** init_matrix(int*** matrix, int size_on_x, int size_on_y, int size_on_z)
{
    matrix = new int** [size_on_x];
    for (int i = 0; i < size_on_x; i++)
    {
        matrix[i] = new int*[size_on_y];
        for (int j = 0; j < size_on_y; j++)
        {
            matrix[i][j] = new int[size_on_z];
            for (int k = 0; k < size_on_z; k++)
            {
                matrix[i][j][k] = 0;
            }
        }
    }
    return (matrix);
}

int*** spiral(int*** matrix, int size_on_x, int size_on_y, int size_on_z, int z)
{
    vector<vector <int>> vector_3;
    for (int i = 0; i < size_on_x; i++)
    {
        for (int j = 0; j < size_on_y; j++)
        {
            for (int k = 0; k < size_on_y; k++)
            {
                matrix[i][j][k] = rand() % 10;
                if (matrix[i][j][k] == z)
                {
                    vector_3.push_back({ i, j, k });
                }
            }
        }
    }
    for (const auto& i : vector_3)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return (matrix);
}

