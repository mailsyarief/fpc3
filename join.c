#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]){
	int n1, n2, f1, f2;
	char buf1[500], buf2[500], hasil[500];
	if((f1 = open(argv[1], O_RDONLY)) < 0){
		printf(1, "failed to read %s\n", argv[1]);
		exit();
	}
	if((f2 = open(argv[2], O_RDONLY)) < 0){
		printf(1, "failed to read %s\n", argv[2]);
		exit();
	}
	close(f1);
	close(f2);
	printf(1, "%s\n", hasil);
}
