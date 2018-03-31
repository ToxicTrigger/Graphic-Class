#include <Windows.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

ostream& XM_CALLCONV operator << (ostream& os, FXMMATRIX m)
{
	for (int i = 0; i < 4; ++i)
	{
		os << XMVectorGetX(m.r[i]) << "\t";
		os << XMVectorGetY(m.r[i]) << "\t";
		os << XMVectorGetZ(m.r[i]) << "\t";
		os << XMVectorGetW(m.r[i]);
		os << endl;
	}
	return os;
}

int main( )
{
	XMMATRIX A
	(
		1.0f, 0.0f, 4.0f, 0.0f,
		-2.0f, 3.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	);
	XMMATRIX B
	(
		1.0f, 2.0f, 0.0f, 0.0f,
		2.0f, -4.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	);

	XMMATRIX C
	(
		1.0f, 0.0f, 0.0f, 0.0f,
		-2.0f, 3.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	);

	XMMATRIX D
	(
		1.0f, 2.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 3.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	);

	cout << "살려주세요" << endl;
	cout << "B + C = "	<< endl << B + C << endl;
	cout << "B - C = "	<< endl << B - C << endl;
	cout << "B * A = "	<< endl << B * A << endl;
	cout << "A * D = "	<< endl << A * D << endl;
	cout << "C * A = "	<< endl << C * A << endl;
	cout << "A tr = " << endl << XMMatrixTranspose(A) << endl;
	cout << "B tr = " << endl << XMMatrixTranspose(B) << endl;
	cout << "C * I = " << endl << C * XMMatrixIsIdentity(C) << endl;
	cout << "A * 2 = " << endl << A * 2 << endl;

	cout << "==============================" << endl;

	XMMATRIX T
		(
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			5.0f, -10.0f, 1.0f, 1.0f
		);

	XMMATRIX Ry = XMMatrixRotationY(45);
	XMMATRIX S = XMMatrixScaling(3,1,3);


	XMMATRIX p
	(
		2.0f, 3.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	);


	XMMATRIX q
	(
		3.0f, 1.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	);

	cout << "pT = " << endl << p * T << endl;
	cout << "qT = " << endl << q * T << endl;
	cout << "pS = " << endl << q * S << endl;
	cout << "SRT = " << endl << S * Ry * T << endl;
	cout << "qSRT = " << endl << q * S * Ry * T << endl;
	cout << "pSRT = " << endl << p * S * Ry * T << endl;

	

	getchar();
}
