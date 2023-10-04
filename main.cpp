#include <Novice.h>

const char kWindowTitle[] = "LC1D_02_ウノ_リュウト";

struct Matrix2x2 {
	float m[2][2];
};

struct Vector2
{
	float x;
	float y;
};
//1 行列の加法
Matrix2x2 Add(Matrix2x2 matrix1, Matrix2x2 matrixx2)
{
	Matrix2x2 result;
	result.m[0][0] = matrix1.m[0][0] + matrixx2.m[0][0];
	return result;
};

//2 行列の減法
Matrix2x2 Subtract(Matrix2x2 matrix1, Matrix2x2 matrixx2)
{
	return { 0 };
};

//３　行列の積
Matrix2x2 Multiply(Matrix2x2 matrix1, Matrix2x2 matrixx2)
{
	return { 0 };
};

//４　ベクトルと行列の積
Vector2 Multiply(Vector2 vector, Matrix2x2 matrix)
{
	return { 0 };
};

static const int kPowHeight = 20;

static const int kColumnWidth = 44;

void MatrixScreenPrintf(int x, int y, Matrix2x2 matrix) {
	for (int row = 0; row < 2; ++row) {
		for (int column = 0; column < 2; ++column) {
			Novice::ScreenPrintf(
				x + column * kColumnWidth, y + row *
				kPowHeight, "%.02f", matrix, matrix.m[row][column]);


		}
	}
}
void VectorScreenPrintf(int x, int y, Vector2 vector) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
}



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	




	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		

		Matrix2x2 m1;
		m1.m[0][0] = 1.0f;
		m1.m[0][1] = 2.0f;
		m1.m[1][0] = 3.0f;
		m1.m[1][1] = 4.0f;

		Matrix2x2 m2;
		m2.m[0][0] = 5.0f;
		m2.m[0][1] = 6.0f;
		m2.m[1][0] = 7.0f;
		m2.m[1][1] = 8.0f;
		Vector2 v = { 10,20 };



		Matrix2x2 resultAdd = Add(m1,m2);
		Matrix2x2 resultSubtract = Subtract(m1, m2);
		Matrix2x2 resultMultiply = Multiply(m1,m2);
		Vector2 resultVector = Multiply(v, m1);

		MatrixScreenPrintf(0, kPowHeight * 0, resultAdd);
		MatrixScreenPrintf(0, kPowHeight * 2+10, resultSubtract);
		MatrixScreenPrintf(0, kPowHeight * 4+20, resultMultiply);
		VectorScreenPrintf(0, kPowHeight * 6 + 30, resultVector);



		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
