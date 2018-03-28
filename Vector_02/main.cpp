#include <Windows.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v)
{
	XMFLOAT4 dest;
	XMStoreFloat4(&dest, v);

	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ", " << dest.w << ")";
	return os;
}

int main( )
{
	cout.precision(8);
	
	XMVECTOR a = XMVectorSet(1.0f, 2.0f, 1.0f, 0.0f);
	XMVECTOR b = XMVectorSet(1.0f, 0.0f, 1.0f, 0.0f);
	XMVECTOR c = XMVectorSet(2.0f, 2.0f, 0.0f, 0.0f);
	XMVECTOR d = XMVectorSet(1.0f, 2.0f, 0.0f, 0.0f);

	cout << " a + b = " << a + b << endl;
	cout << " b - d = " << b - d << endl;
	cout << " a * b = " << XMVector3Dot(a, b) << endl;
	cout << " b * d = " << XMVector3Dot(b, d) << endl;
	cout << " 2 * c = " << 2 * c << endl;
	cout << "|| b || = " << XMVector3Length(b) << endl;
	cout << "|| c || = " << XMVector3Length(c) << endl;
	cout << "|| d || = " << XMVector3Length(d) << endl;
	cout << "nor c = " << XMVector3Normalize(c) << endl;
	cout << "angle b , d = " << XMConvertToDegrees( XMVectorGetX( XMVector3AngleBetweenVectors(b, d))) << endl;





	getchar();
	return 0;
}

