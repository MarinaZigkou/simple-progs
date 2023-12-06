#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{

	/*
	Parameter initialization
	*/
	char seq[ 10000 ];
	char seq2[ 10000 ];
	char seq3[ 10000 ];
	char seq4[ 10000 ];
	int length, z, i, y, count, count2;


	printf("Enter your sequences:\n");

	
        while (scanf("%s", seq ) == 1 )   // It reads a string from the standard input and continues 
				          // looping until it encounters an issue or the end of file. 
					  // The entered data is stored in the string 'seq'.
        {
                length = strlen(seq);       // Determining the length of the string 'seq'.
                count = 0;                  // Setting the value of the variable named 'count' to zero.
                seq2[0] = '\0';             // Initializing or clearing the string named 'seq2'.

		/*
		Checking whether the string correspond to a DNA sequence. 
		*/
                for (z=0; z<=length; z++)   
                {
                        if (seq[z] == 'A' || seq[z] == 'T' || seq[z] == 'C' || seq[z] == 'G')     // Using the length of the string as the maximum 
												  // value, it checks each position one by one for 
												  // the presence or absence of one of the correct
												  // bases A, T, C or G.
                        {
                                count++;            // Every time it encounters one of the four valid 
					            // DNA bases, the variable 'count' increases by 1.
                        }
                }
                if ( count < length )       // If anything other than the DNA bases is detected, 
			                    // 'count' couldn't increase to reach the length of the string, 
			                    // rendering the string invalid.
                {
                        printf("You did not enter a valid sequence\n");
                }		
                if (count == length )       // If 'count' equals 'length', we proceed to the next set of checks.
                {
			if (length <= 5)                          // Sequence with less than 6 bases, due to its short length, 
				                                  // is ineligible as it lacks both a start codon and a stop 
								  // codon, leading to its rejection.
			{
				printf("The sequence %s does not meet any of the requirements\n", seq );
			}
			else if (length <= 8 && length >= 6 )     // If the sequence consists of 6 to 8 bases, it is 
								  // checked for the presence of a start and a stop codon.
			{
				for (i=0; i<=length; i++)         // The entire sequence is checked.
                        	{
                        		if (seq[0] == 'A' && seq[1] == 'T' && seq[2] == 'G' )    // The sequence is examined to see if it starts with ATG.
                                	{
                                		if (seq[length-3] == 'T' && seq[length-2] == 'A' && seq[length-1] == 'A' )       // The sequence is examined to see if it ends with TAA.
                                        	{
                                        		printf("The sequence %s starts with ATG and ends with TAA\n", seq );
                                                	break;
                                        	}
                                        	else if (seq[length-3] == 'T' && seq[length-2] == 'A' && seq[length-1] == 'G' )  // The sequence is examined to see if it ends with TAG.
                                        	{
                                        		printf("The sequence %s starts with ATG and ends with TAG\n", seq );
                                                	break;
                                        	}
                                        	else if (seq[length-3] == 'T' && seq[length-2] == 'G' && seq[length-1] == 'A' )  // The sequence is examined to see if it ends with TGA.
                                        	{
                                        		printf("The sequence %s starts with ATG and ends with TGA\n", seq );
                                                	break;
                                        	}
                                        	else     // If the sequence start with ATG, but it does not end with a stop 
							 // codon it returns to the beginning of the program to enter a new sequence.
                                        	{
                                        		printf("The sequence %s does not meet the requirements, as it does not end with any of the stop condons\n", seq );
							break;
						}
					}
					else    // If the sequence does not start with ATG, it returns to the beginning 
						// of the program to enter a new sequence.
					{
						printf("The sequence %s does not meet the requirements\n", seq );
						break;
					}
				}
			}
			else if (length >= 9)   // If the sequence consists of 9 bases or more, it is checked for the 
				                // presence of a start codon, a stop codon and the absence of a stop 
				                // codon in the intermediate region.
			{
				for (i=0; i<=length; i++)   // The entire sequence is checked.
                        	{
                        		if (seq[0] == 'A' && seq[1] == 'T' && seq[2] == 'G' )    // The sequence is examined to see if it starts with ATG.
                                	{
                                        	if (seq[length-3] == 'T' && seq[length-2] == 'A' && seq[length-1] == 'A' )        // The sequence is examined to see if it ends with TAA.
                                        	{
							seq2[i] = seq[i];                                                         // If it ends with TAA, the sequence from 'seq' will also be stored in 'seq2'.
						}
                                        	else if (seq[length-3] == 'T' && seq[length-2] == 'A' && seq[length-1] == 'G' )   // The sequence is examined to see if it ends with TAG.
                                        	{
							seq3[i] = seq[i];                                                         // If it ends with TAG, the sequence from 'seq' will also be stored in 'seq2'.
						}
                                        	else if (seq[length-3] == 'T' && seq[length-2] == 'G' && seq[length-1] == 'A' )   // The sequence is examined to see if it ends with TGA.
                                        	{
							seq4[i] = seq[i];							  // If it ends with TGA, the sequence from 'seq' will also be stored in 'seq4'.
						}
                                        	else     // If the sequence start with ATG, but it does not end with a stop 
							 // codon it returns to the beginning of the program to enter a new sequence.
                                        	{
                                                	printf("The sequence %s does not meet the requirements, as it does not end with any of the stop codons\n", seq );
                                                	break;
                                        	}
					}
					else    // If the sequence does not start with ATG, it returns to the beginning 
						// of the program to enter a new sequence.
                                	{
                                        	printf("The sequence %s does not meet the requirements\n", seq );
                                        	break;
                                	}
				}
				if ( seq2[0] != '\0' )     // If 'seq2' contains data, the intermediate region will be checked for stop codons.
				{
					count2 = 0;                     // Setting the value of the variable named 'count2' to zero.
					for (y=3; y<=length-4; y++)     // The entire sequence is checked except for the first three and last three bases.
                                	{
                                		if (seq2[y] == 'T' && seq2[y+1] == 'A' && seq2[y+2] == 'A' )        // If the stop codon TAA is identified, the program
														    // returns to the beginning to enter a new sequence.
                                        	{
                                        		printf("The sequence %s does not meet the requirements as it includes the stop codon TAA within its sequence\n", seq2 );
                                                	break;
                                        	}
                                        	else if (seq2[y] == 'T' && seq2[y+1] == 'A' && seq2[y+2] == 'G' )   // If the stop codon TAG is identified, the program
														    // returns to the beginning to enter a new sequence.
                                        	{
                                        		printf("The sequence %s does not meet the requirements as it includes the stop codon TAG within its sequence\n", seq2 );
                                        		break;
                                        	}
                                        	else if (seq2[y] == 'T' && seq2[y+1] == 'G' && seq2[y+2] == 'A' )   // If the stop codon TGA is identified, the program
														    // returns to the beginning to enter a new sequence.
                                        	{
                                        		printf("The sequence %s does not meet the requirements as it includes the stop codon TGA within its sequence\n", seq2 );
                                        		break;
                                        	}
						count2++;                                                           // The value of 'count2' increases as the program struggles
														    // to identify a stop codon in the intermediate region. The 
														    // maximum value it can reach is length-6.
					}
					if ( count2 == length-6 )    // If no stop codon is identified within the intermediate region, 
						                     // the sequence is considered as a standard prokaryotic coding 
						                     // sequence with an ATG start codon and a TAA stop codon.
					{
						printf("The sequence %s starts with ATG and ends with TAA\n", seq2 );
					}
					seq2[0] = '\0';              // Initializing or clearing the string named 'seq2'.
				}
				if ( seq3[0] != '\0' )     // If 'seq3' contains data, the intermediate region will be checked for stop codons.
				{
					count2 = 0;                  // Setting the value of the variable named 'count2' to zero.
					for (y=3; y<=length-4; y++)  // The entire sequence is checked except for the first three and last three bases.
                                	{
                                		if (seq3[y] == 'T' && seq3[y+1] == 'A' && seq3[y+2] == 'A' )        // If the stop codon TAA is identified, the program
														    // returns to the beginning to enter a new sequence.
                                        	{
                                        		printf("The sequence %s does not meet the requirements as it includes the stop codon TAA within its sequence\n", seq3 );
                                                	break;
                                        	}
                                        	else if (seq3[y] == 'T' && seq3[y+1] == 'A' && seq3[y+2] == 'G' )   // If the stop codon TAG is identified, the program
														    // returns to the beginning to enter a new sequence.
                                        	{
                                        		printf("The sequence %s does not meet the requirements as it includes the stop codon TAG within its sequence\n", seq3 );
                                                	break;
                                        	}
                                        	else if (seq3[y] == 'T' && seq3[y+1] == 'G' && seq3[y+2] == 'A' )   // If the stop codon TGA is identified, the program
														    // returns to the beginning to enter a new sequence.
                                        	{
                                        		printf("The sequence %s does not meet the requirements as it includes the stop codon TGA within its sequence\n", seq3 );
                                                	break;
                                        	}
						count2++;                                                           // The value of 'count2' increases as the program struggles
														    // to identify a stop codon in the intermediate region. The 
														    // maximum value it can reach is length-6.
					}
					if ( count2 == length-6 )     // If no stop codon is identified within the intermediate region, 
						                      // the sequence is considered as a standard prokaryotic coding 
						                      // sequence with an ATG start codon and a TAG stop codon.
                                	{
                                        	printf("The sequence %s starts with ATG and ends with TAG\n", seq3 );
                                	}
					seq3[0] = '\0';              // Initializing or clearing the string named 'seq3'.
				}
				if ( seq4[0] != '\0' )     // If 'seq4' contains data, the intermediate region will be checked for stop codons.
                        	{
					count2 = 0;                  // Setting the value of the variable named 'count2' to zero.
                                	for (y=3; y<=length-4; y++)  // The entire sequence is checked except for the first three and last three bases.
                                	{
                                        	if (seq4[y] == 'T' && seq4[y+1] == 'A' && seq4[y+2] == 'A' )        // If the stop codon TAA is identified, the program
														    // returns to the beginning to enter a new sequence.
                                        	{
                                                	printf("The sequence %s does not meet the requirements as it includes the stop codon TAA within its sequence\n", seq4 );
                                                	break;
                                        	}
                                        	else if (seq4[y] == 'T' && seq4[y+1] == 'A' && seq4[y+2] == 'G' )   // If the stop codon TAG is identified, the program
														    // returns to the beginning to enter a new sequence.
                                        	{
                                                	printf("The sequence %s does not meet the requirements as it includes the stop codon TAG within its sequence\n", seq4 );
                                                	break;
                                        	}
                                        	else if (seq4[y] == 'T' && seq4[y+1] == 'G' && seq4[y+2] == 'A' )   // If the stop codon TGA is identified, the program
														    // returns to the beginning to enter a new sequence.
                                        	{
                                                	printf("The sequence %s does not meet the requirements as it includes the stop codon TGA within its sequence\n", seq4 );
                                                	break;
                                        	}
						count2++;                                                           // The value of 'count2' increases as the program struggles
														    // to identify a stop codon in the intermediate region. The 
														    // maximum value it can reach is length-6.
                                	}
					if ( count2 == length-6 )     // If no stop codon is identified within the intermediate region, 
						                      // the sequence is considered as a standard prokaryotic coding 
						                      // sequence with an ATG start codon and a TGA stop codon.
                                	{
                                        	printf("The sequence %s starts with ATG and ends with TGA\n", seq4 );
                                	}
                                	seq4[0] = '\0';               // Initializing or clearing the string named 'seq4'.
				}
			}
		}
	}
}
