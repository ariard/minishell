#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int		main(void)
{
	struct stat *buf;
	struct stat *buf2;
	struct stat *buf3;

	buf = malloc(sizeof(struct stat));
	buf2 = malloc(sizeof(struct stat));
	buf3= malloc(sizeof(struct stat));
	fstat(0, buf);
	stat("/dev/stdin", buf2);
	stat("/dev/random", buf3);
/*	printf("%d\n", buf->st_dev);
	printf("%d\n", buf2->st_dev);
	printf("%d\n", buf3->st_dev);
	printf("%lld\n", buf->st_ino);
	printf("%lld\n", buf2->st_ino);
	printf("%lld\n", buf3->st_ino);
*/	if (buf->st_dev != buf2->st_dev)
		printf("not in terminal");
	else if (buf2->st_ino == buf3->st_ino)
		printf("not in terminal");
	else
		printf("good");
	return (0);
}
