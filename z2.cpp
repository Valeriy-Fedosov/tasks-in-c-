#include <iostream>
//#include <random>

using namespace std;


int** init_matrix(int** matrix, int size_of_matrix);
int** spiral_1(int** matrix, int size);
int** spiral_2(int** matrix, int size);
void print_matrix(int** matrix, int size_of_matrix);
void del_memory(int** matrix, int size_of_matrix);

int main()
{
    int** matrix = NULL;
    int size, direct;
    
    size = 3 + rand() % 8;
    direct = rand() % 2;

    matrix = init_matrix(matrix, size);

    direct == 1 ? matrix = spiral_1(matrix, size): matrix = spiral_2(matrix, size);
    
    print_matrix(matrix, size);
    del_memory(matrix, size);
    return 0;
}

int** init_matrix(int** matrix, int size_of_matrix)
{
    matrix = new int* [size_of_matrix];
    for (int i = 0; i < size_of_matrix; i++)
    {
        matrix[i] = new int[size_of_matrix];
        for (int j = 0; j < size_of_matrix; j++)
        {
            matrix[i][j] = 0;
        }
    }
    return (matrix);
}

int** spiral_1(int** matrix, int size)
{
    int value = 1, cur_str = 0, cur_col = 0;
    for (int border = 0; 2 * border < size; border++)
    {
        cur_str = border;
        cur_col = border;
        for (; cur_col < size - border; cur_col++)
        {
            matrix[cur_str][cur_col] = value++;
        }
        for (cur_col--, cur_str++; cur_str < size - border; cur_str++)
        {
            matrix[cur_str][cur_col] = value++;
        }
        for (cur_str--, cur_col--; cur_col >= border; cur_col--)
        {
            matrix[cur_str][cur_col] = value++;
        }
        for (cur_col++, cur_str--; cur_str > border; cur_str--)
        {
            matrix[cur_str][cur_col] = value++;
        }
    }
    return (matrix);
}

int** spiral_2(int** matrix, int size)
{
    int value = 1, cur_str = 0, cur_col = 0;
    for (int border = 0; 2 * border < size; border++)
    {
        cur_str = border;
        cur_col = border;
        for (; cur_col < size - border; cur_col++)
        {
            matrix[cur_col][cur_str] = value++;
        }
        for (cur_col--, cur_str++; cur_str < size - border; cur_str++)
        {
            matrix[cur_col][cur_str] = value++;
        }
        for (cur_str--, cur_col--; cur_col >= border; cur_col--)
        {
            matrix[cur_col][cur_str] = value++;
        }
        for (cur_col++, cur_str--; cur_str > border; cur_str--)
        {
            matrix[cur_col][cur_str] = value++;
        }
    }
    return (matrix);
}

void print_matrix(int** matrix, int size_of_matrix)
{
    for (int i = 0; i < size_of_matrix; i++)
    {
        for (int j = 0; j < size_of_matrix; j++)
        {
           cout << matrix[i][j] << "\t ";
        }
        cout << endl;
    }
    cout << endl;
}

void del_memory(int** matrix, int size_of_matrix)
{
    for (int i = 0; i < size_of_matrix; i++)
        delete[] matrix[i];
    delete[] matrix;
    matrix = NULL;
}
