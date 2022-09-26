/*
 * author: 赖弘霖
 * date: 2022/9/26
 * topic: 二分查找
 * */

Position BinarySearch( List L, ElementType X )
{
    Position left = 1,right = L->Last;
    while(left <= right)
    {
        Position mid = (right - left) / 2 + left;
        if(L->Data[mid] < X) left = mid + 1;
        else if(L->Data[mid] > X) right = mid - 1;
        else if(L->Data[mid] == X) return mid;
    }
    return NotFound;
}
