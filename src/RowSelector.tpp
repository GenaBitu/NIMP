#include "RowSelector.hpp"

//#include "NodeSystem/NodeData.hpp" // DEBUG - Sometimes crashes without this... ??

template<class T, class U>
RowSelector<T, U>::RowSelector(T* matrix, int row, int width) : matrix{matrix}, row{row}, width{width} {}

template<class T, class U>
U& RowSelector<T, U>::operator[](int index)
{
    return matrix->data[row * width + index];
}
