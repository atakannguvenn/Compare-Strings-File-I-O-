#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n=0, j=0, z=0, J=0, r, l, k=0;
    	FILE *fp;
	char names[200][50], temp[200][50];
	fp=fopen("Names.txt","r");
	if (fp==NULL)
    	{
        	printf("Could not open the file.\n");
       	 	return 0;
    	}
   	while (fgets(names[n], 50, (FILE*)fp)!=NULL)
        	n++;
    	while(J<=n-2)
    	{
        	while(j<=n-2)
        	{
            		while (names[j][z]!='\0' || names[j+1][z]!='\0')
            		{
                		if (names[j][z]>names[j+1][z])
                		{
					z=0;
				    	for(r=0; names[j][r]!='\0'; r++);
					r--;
					for(l=0; names[j+1][l]!='\0'; l++);
					l--;
					while(z<=r || z<=l)
                    			{
						temp[j][z]=names[j][z];
						names[j][z]=names[j+1][z];
						names[j+1][z]=temp[j][z];
						z++;
                    			}
					if(r<l)
						names[j][z]='\0';
					if(l<r)
						names[j+1][z]='\0';
					goto Plswork;
                		}
				if (names[j][z]==names[j+1][z])
				    	z++;
				if (names[j][z]<names[j+1][z])
				    	goto Plswork;
			}
			Plswork:;
			z=0;
			j++;
        	}
		j=0;
		J++;
    	}
	fclose(fp);
	fp=fopen("Sorted Names.txt","w");
	if (fp==NULL)
    	{
		printf("Could not open the file.\n");
		return 0;
    	}
    	while(k<=n-1)
    	{
		fprintf(fp,"%s\n",names[k]);
		k++;
    	}
	printf("\n\nAll finished check your new txt file :)\n\n");
	return 0;
}
