#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>

int main()
{
	int i = 0, j, k;
	char buf[21], line[104];
	FILE *files[5];
	time_t t = time(NULL);
	struct tm *currTime = localtime(&t);
	buf[1] = 0;
	buf[0] = '0' + currTime->tm_hour / 10;
	files[0] = fopen(buf, "r");
	buf[0] = '0' + currTime->tm_hour % 10;
	files[1] = fopen(buf, "r");
	files[2] = fopen("points", "r");
	buf[0] = '0' + currTime->tm_min / 10;
	files[3] = fopen(buf, "r");
	buf[0] = '0' + currTime->tm_min % 10;
	files[4] = fopen(buf, "r");
	for (i = 0; i < 11; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			fgets(buf, 25, files[j]);
			for (k = 0; k < 20; ++k)
				line[21 * j + k] = buf[k];
			line[21 * j + 20] = ' ';
		}
		printf("%s", line);
		/*for (j = 0; j < 104; ++j)
		{
			printf("%c", line[j]);

		}*/
		//printf("\n");
	}
	getchar();
	return 0;
}
