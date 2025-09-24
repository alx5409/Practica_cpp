#include <iostream>
#include <vector>

void SelectionSort(std::vector<int>* a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        for (int k = i + 1; k < n; k++)
        {
            if (a[k] < a[j])
            {
                j = k;
                std::swap(a[i], a[j]);
            }
        }
    }
}

int main()
{
    std::vector<int>num = {2, 3, 5, 4, 8, 6, 1};
    std::cout << "El vector inicial es: ";
    for(int i = 0; i < num.size(); i++)
    {
        std::cout << num[i]<< " ";
    }
    std::cout << std::endl;

    std::cout << "Y el vector tras ordenar es: ";
    SelectionSort(&num, num.size());
    for(int i = 0; i < num.size(); i++)
    {
        std::cout << num[i]<< " ";
    }
    std::cout << std::endl;



    return 0;
}