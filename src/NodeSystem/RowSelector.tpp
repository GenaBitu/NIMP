#include "NodeSystem/RowSelector.hpp"

//#include "include/NodeSystem/NodeData.hpp" // DEBUG - Sometimes crashes without this... ??

template<class T, class U>
RowSelector<T, U>::RowSelector(T* nodeData, int row, int width) : nodeData{nodeData}, row{row}, width{width} {}

template<class T, class U>
U& RowSelector<T, U>::operator[](int index)
{
    return nodeData->data[row * width + index];
}
