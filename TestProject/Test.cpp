#include <stdio.h>
#include <math.h>

void main()
{
	int matrix[7][7] = {
		0, 0, 0, 0, 0, 0, 0,
		0, 0, 5, 5, 0, 0, 0,
		0, 5, 9, 9, 5, 0, 0,
		0, 5, 9, 9, 5, 0, 0,
		0, 0, 5, 5, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0
	};

	double ratio;
	printf("축소 또는 확대배율 : ");
	scanf("%lf", &ratio);

	int newSize = (int)(6 * ratio);
	int *result = new int[newSize*newSize];

	for (int y = 0; y<newSize; y++)
	{
		for (int x = 0; x<newSize; x++)
		{
			double r_org_x = x / ratio;
			double r_org_y = y / ratio;
			int    i_org_x = floor(r_org_x);
			int    i_org_y = floor(r_org_y);
			double sx = r_org_x - i_org_x;
			double sy = r_org_y - i_org_y;
			double I1 = matrix[i_org_y][i_org_x];
			double I2 = matrix[i_org_y][i_org_x + 1];
			double I3 = matrix[i_org_y + 1][i_org_x + 1];
			double I4 = matrix[i_org_y + 1][i_org_x];
			double newValue = I1 * (1 - sx)*(1 - sy) +
				I2 * sx*(1 - sy) +
				I3 * sx*sy +
				I4 * (1 - sx)*sy;
			result[y*newSize + x] = (int)newValue;
		}
	}

	printf("Result :\n");
	for (int y = 0; y<newSize; y++)
	{
		for (int x = 0; x<newSize; x++)
		{
			printf("%2d", result[y*newSize + x]);
		}
		printf("\n");
	}

	delete[] result;
}