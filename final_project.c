#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{

//teliko project

	char seq[ 10000 ];
	char seq2[ 10000 ];
	char seq3[ 10000 ];
	char seq4[ 10000 ];
	int length, z, i, y, count, count2;

//	seq2[0] = '\0';
//	seq3[0] = '\0';
//	seq4[0] = '\0';

	printf("Enter your sequences:\n");

        while (scanf("%s", seq ) == 1 )
        {
                length = strlen(seq);
                count = 0;
                seq2[0] = '\0';
                for (z=0; z<=length; z++)
                {
                        if (seq[z] == 'A' || seq[z] == 'T' || seq[z] == 'C' || seq[z] == 'G')
                        {
                                count++;
                        }
                }
                if ( count < length )
                {
                        printf("You did not enter a valid sequence\n");
                }
                if (count == length )
                {
			if (length <= 5)
			{
				printf("The sequence %s does not meet any of the requirements\n", seq );
			}
			else if (length <= 8 && length >= 6 )
			{
				for (i=0; i<=length; i++)
                        	{
                        		if (seq[0] == 'A' && seq[1] == 'T' && seq[2] == 'G' )
                                	{
                                		if (seq[length-3] == 'T' && seq[length-2] == 'A' && seq[length-1] == 'A' )
                                        	{
                                        		printf("The sequence %s starts with ATG and ends with TAA\n", seq );
                                                	break;
                                        	}
                                        	else if (seq[length-3] == 'T' && seq[length-2] == 'A' && seq[length-1] == 'G' )
                                        	{
                                        		printf("The sequence %s starts with ATG and ends with TAG\n", seq );
                                                	break;
                                        	}
                                        	else if (seq[length-3] == 'T' && seq[length-2] == 'G' && seq[length-1] == 'A' )
                                        	{
                                        		printf("The sequence %s starts with ATG and ends with TGA\n", seq );
                                                	break;
                                        	}
                                        	else
                                        	{
                                        		printf("The sequence %s does not meet the requirements, as it does not end with any of the stop condons\n", seq );
							break;
						}
					}
					else
					{
						printf("The sequence %s does not meet the requirements\n", seq );
						break;
					}
				}
			}
			else if (length >= 9)
			{
				for (i=0; i<=length; i++)
                        	{
                        		if (seq[0] == 'A' && seq[1] == 'T' && seq[2] == 'G' )
                                	{
                                        	if (seq[length-3] == 'T' && seq[length-2] == 'A' && seq[length-1] == 'A' )
                                        	{
							seq2[i] = seq[i];
						}
                                        	else if (seq[length-3] == 'T' && seq[length-2] == 'A' && seq[length-1] == 'G' )
                                        	{
							seq3[i] = seq[i];
						}
                                        	else if (seq[length-3] == 'T' && seq[length-2] == 'G' && seq[length-1] == 'A' )
                                        	{
							seq4[i] = seq[i];
						}
                                        	else
                                        	{
                                                	printf("The sequence %s does not meet the requirements, as it does not end with any of the stop codons\n", seq );
                                                	break;
                                        	}
					}
					else
                                	{
                                        	printf("The sequence %s does not meet the requirements\n", seq );
                                        	break;
                                	}
				}
				if ( seq2[0] != '\0' )
				{
					count2 = 0;
					for (y=3; y<=length-4; y++)
                                	{
                                		if (seq2[y] == 'T' && seq2[y+1] == 'A' && seq2[y+2] == 'A' )
                                        	{
                                        		printf("The sequence %s does not meet the requirements as it includes the stop codon TAA within its sequence\n", seq2 );
                                                	break;
                                        	}
                                        	else if (seq2[y] == 'T' && seq2[y+1] == 'A' && seq2[y+2] == 'G' )
                                        	{
                                        		printf("The sequence %s does not meet the requirements as it includes the stop codon TAG within its sequence\n", seq2 );
                                        		break;
                                        	}
                                        	else if (seq2[y] == 'T' && seq2[y+1] == 'G' && seq2[y+2] == 'A' )
                                        	{
                                        		printf("The sequence %s does not meet the requirements as it includes the stop codon TGA within its sequence\n", seq2 );
                                        		break;
                                        	}
						count2++;
					}
					if ( count2 == length-6 )
					{
						printf("The sequence %s starts with ATG and ends with TAA\n", seq2 );
					}
					seq2[0] = '\0';
				}
				if ( seq3[0] != '\0' )
				{
					count2 = 0;
					for (y=3; y<=length-4; y++)
                                	{
                                		if (seq3[y] == 'T' && seq3[y+1] == 'A' && seq3[y+2] == 'A' )
                                        	{
                                        		printf("The sequence %s does not meet the requirements as it includes the stop codon TAA within its sequence\n", seq3 );
                                                	break;
                                        	}
                                        	else if (seq3[y] == 'T' && seq3[y+1] == 'A' && seq3[y+2] == 'G' )
                                        	{
                                        		printf("The sequence %s does not meet the requirements as it includes the stop codon TAG within its sequence\n", seq3 );
                                                	break;
                                        	}
                                        	else if (seq3[y] == 'T' && seq3[y+1] == 'G' && seq3[y+2] == 'A' )
                                        	{
                                        		printf("The sequence %s does not meet the requirements as it includes the stop codon TGA within its sequence\n", seq3 );
                                                	break;
                                        	}
						count2++;
					}
					if ( count2 == length-6 )
                                	{
                                        	printf("The sequence %s starts with ATG and ends with TAG\n", seq3 );
                                	}
					seq3[0] = '\0';
				}
				if ( seq4[0] != '\0' )
                        	{
					count2 = 0;
                                	for (y=3; y<=length-4; y++)
                                	{
                                        	if (seq4[y] == 'T' && seq4[y+1] == 'A' && seq4[y+2] == 'A' )
                                        	{
                                                	printf("The sequence %s does not meet the requirements as it includes the stop codon TAA within its sequence\n", seq4 );
                                                	break;
                                        	}
                                        	else if (seq4[y] == 'T' && seq4[y+1] == 'A' && seq4[y+2] == 'G' )
                                        	{
                                                	printf("The sequence %s does not meet the requirements as it includes the stop codon TAG within its sequence\n", seq4 );
                                                	break;
                                        	}
                                        	else if (seq4[y] == 'T' && seq4[y+1] == 'G' && seq4[y+2] == 'A' )
                                        	{
                                                	printf("The sequence %s does not meet the requirements as it includes the stop codon TGA within its sequence\n", seq4 );
                                                	break;
                                        	}
						count2++;
                                	}
					if ( count2 == length-6 )
                                	{
                                        	printf("The sequence %s starts with ATG and ends with TGA\n", seq4 );
                                	}
                                	seq4[0] = '\0';
					printf("seq4 otan exv TGA sto telos meta ton mhdeninismo %s\n", seq4);
				}
			}
		}
	}
}
