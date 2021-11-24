#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.1415926
#define DEGREE_TO_RADIAN(D) ((PI/180)*(D))

int compare(int X1, int Y1, double X2, double Y2)
{
	if (X1 >= 0) {
		if ((Y2/X2)*X1 <= Y1) {
			return 1;
		}
	}
	else {
		if ((Y2/X2)*X1 > Y1) {
			return 1;
		}
	}

	return 0;
}

int main(void)
{
	int T, P, X, Y;
	int a, b;
	double degree, X2, Y2, dist1, dist2;
	int ans;

	//freopen("input_1.txt", "r", stdin);

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> P >> X >> Y;

		X -= 50;
		Y -= 50;

		degree = ((double)P / 100) * 360;
		Y2 = 50 * cos(DEGREE_TO_RADIAN(degree));
		X2 = 50 * sin(DEGREE_TO_RADIAN(degree));

		ans = 0;

		if (P == 0 || (P == 50 && X < 0)) {
			ans = 0;
		}
		else if ((X == 0 && Y == 0) || (P == 100)) {
			ans = 1;
		}
		else if (P <= 25) {
			if (X >= 0 && Y >= 0) {
				ans = compare(X, Y, X2, Y2);
			}
		}
		else if (P <= 50) {
			if (X >= 0 && Y >= 0) {
				ans = 1;
			}
			else if (X >= 0 && Y <= 0) {
				ans = compare(X, Y, X2, Y2);
			}
		}
		else if (P <= 75) {
			if (X >= 0) {
				ans = 1;
			}
			else if (X < 0 && Y <= 0) {
				ans = compare(X, Y, X2, Y2);
			}
		}
		else {
			if (X >= 0 || (X < 0 && Y < 0)) {
				ans = 1;
			}
			if (X < 0 && Y >= 0) {
				ans = compare(X, Y, X2, Y2);
			}
		}

		dist2 = sqrt((X*X)+(Y*Y));

		if (ans == 1 && 50 < dist2) {
			ans = 0;
		}

		printf("#%d %d\n", i+1, ans);
	}

	return 0;
}
