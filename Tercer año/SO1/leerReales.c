#include <stdio.h>
#include <fcntl.h>

int main()
{
	int arch, i;
	double d;

	arch =	OPEN("pepe.txt",O_RDWR|O_CREAT|O_APPEND,0666);
	for(i=d=0; i<10; i++, d+=0.1)
	{
		write(arch,&d,sizeof(d));
	}

	lseek(arch,-1L*sizeof(d),SEEK_END);

	for(i=0; i<10; i++, lseek(arch,-2L*sizeof(d),SEEK_CUR))
	{
		read(arch,&d,sizeof(d));
		printf("%f\n",d);
	}
	close(arch);
	return 0;

}
