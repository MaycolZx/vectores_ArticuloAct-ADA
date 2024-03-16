#include <iostream>

//typedef int Type;
template <typename Type> 
class CVector{
private:
	Type* m_pVect;
	int m_nCount, 
		m_nMax, 
		m_nDelta; 
	void Resize(); 
public:
	CVector(int delta = 10);
	void Insert(Type elem);
	void PrintVal();
	~CVector();
};

template <typename Type>
CVector<Type>::CVector(int delta) {
	m_pVect = new int[delta];
	m_nCount = 0;
	m_nMax = delta;
	m_nDelta = delta;
}
template <typename Type>
CVector<Type>::~CVector() {}

template <typename Type> 
void CVector<Type>::Resize() {
	int* pTemp = new int[m_nMax + m_nDelta];
	for (int i = 0; i < m_nMax; i++) {
		pTemp[i] = m_pVect[i];
	}
	delete[] m_pVect;
	m_pVect = pTemp;
	m_nMax += m_nDelta;
}

template <typename Type>
void CVector<Type>::Insert(Type elem){
	if (m_nCount == m_nMax)
		Resize();
	m_pVect[m_nCount++] = elem;
}

template <typename Type>
void CVector<Type>::PrintVal() {
	for (int i = 0; i < m_nCount; i++) {
		std::cout << m_pVect[i] << " ";
	}
	std::cout << std::endl;
}


int main() {
	CVector<int> vectorEx;

	for (int i = 0; i < 15; i++) {
		vectorEx.Insert(i * 10);
	}
	vectorEx.PrintVal();

	return 0;
}