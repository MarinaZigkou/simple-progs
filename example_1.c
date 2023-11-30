#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	char seq[ 1000 ];
	int length, count, i;
	float GCcontent;

	count = 0;
	scanf("%s", seq );
	length = strlen( seq );
	for (i=0; i<=length; i++)
	{
		if (seq[i] == 'C' || seq[i] == 'G')
		{
			count++;
		}
	}
	GCcontent = 100.0*count/length;
	printf("The GC content percentage in the sequence is: %f\n", GCcontent);

}

