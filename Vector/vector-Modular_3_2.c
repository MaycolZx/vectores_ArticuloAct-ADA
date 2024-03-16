#include <stdlib.h>
#include <stdio.h>
 
int* gpVect = NULL;

struct Vector
{
    int* m_pVect, m_nCount, m_nMax, m_nDelta;
};

void Insert(struct Vector* pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax) 
        Resize(pThis); 
    pThis->m_pVect[pThis->m_nCount++] = elem;
}
void Resize(struct Vector* pThis)
{
    pThis->m_pVect = realloc(gpVect, sizeof(int) *
        (pThis->m_nMax + pThis->m_nDelta));
    pThis->m_nMax += pThis->m_nDelta;
}


int main(int argc, char** argv) {

	return 0;
}