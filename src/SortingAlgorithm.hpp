#pragma once
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

template<Sortable T>
void ordina_famiglia_heap_tree(vector<T>& v, unsigned int n, unsigned int i)
{
    unsigned int largest = i;
    unsigned int left = 2 * i + 1;
    unsigned int right = 2 * i + 2;

    if (left<n&& v[left]>v[largest])
	{
        largest = left;
    }

    if (right < n && v[right] > v[largest])
	{
        largest = right;
    }

    if (largest != i)
	{
		T temp = v[i];
		v[i] = v[largest];
		v[largest] = temp;
        ordina_famiglia_heap_tree(v, n, largest);
    }
}

template<Sortable T>
void trova_massimo_heap_tree(vector<T>& v, const unsigned int n){
	int pos_ultimo_nodo_non_foglia = floor(n/2)-1;
	for(int i = pos_ultimo_nodo_non_foglia; i >=0; i--){
		ordina_famiglia_heap_tree(v,n,i);
	}
}

template<Sortable T>
void HeapSort(vector<T>& v)
{
    const unsigned int n = v.size();

    trova_massimo_heap_tree(v, n);

    for (int i = n - 1; i > 0; i--){
		T temp = v[0];
		v[0] = v[i];
		v[i] = temp;
        ordina_famiglia_heap_tree(v, i, 0);
	}
}

template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
    const unsigned int n = v.size();
    for(unsigned int i = 0; i < n - 1; i++)
    {
        for(unsigned int j = i + 1; j < n; j++)
        {
            if(v[j] < v[i]){
				T temp = v[i];
				v[i]=v[j];
				v[j]=temp;
			}
        }
    }
}

}


