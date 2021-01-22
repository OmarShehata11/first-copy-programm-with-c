
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{

	if(argc < 3)
		return 1;
	int FileSrc=open(argv[1], O_RDONLY);

	if (FileSrc == -1)

		printf("there is no file called %s !!\n", argv[1] );

	else 
	{
	

		int FileDst=open(argv[2], O_CREAT | O_WRONLY, S_IRUSR);

		if (FileDst == -1)
			
			printf("there is already file called %s!!\n", argv[2] );

		else
		{
			char buffer[2];
			ssize_t charCount;

			while (  (charCount = read(FileSrc, buffer, sizeof(buffer))  ) ) // if the value is true :: !=0 
			{
				write(FileDst, buffer, charCount);

			}
		}
	}	

}
