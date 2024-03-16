#include <iostream>

class CVector
{
private:
	int* m_pVect = NULL;
	int m_nCount;
	int m_nMax;
	int m_nDelta;
	void Resize();
public:
	CVector(int delta = 10);
	void Insert(int elem); 
	void PrintVal();
	~CVector();
};

CVector::CVector(int delta){
	m_pVect = new int[delta]; 
	m_nCount = 0; 
	m_nMax = delta; 
	m_nDelta = delta;
}

CVector::~CVector() {}

void CVector::Insert(int elem){
	if (m_nCount == m_nMax) {
		Resize();
	}
	m_pVect[m_nCount++] = elem;
}

void CVector::Resize() {
	int* pTemp = new int[m_nMax + m_nDelta];
	for (int i = 0; i < m_nMax; i++) {
		pTemp[i] = m_pVect[i];
	}
	delete[] m_pVect;
	m_pVect = pTemp;
	m_nMax += m_nDelta;
}

void CVector::PrintVal() {
	for (int i = 0; i < m_nCount; i++) {
		std::cout << m_pVect[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	CVector vectorEx;

	for (int i = 0; i < 15; i++) {
		vectorEx.Insert(i * 10);
	}

	vectorEx.PrintVal();

	return 0;
}