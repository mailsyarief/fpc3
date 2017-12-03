#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]){
	int f;
	if(argc != 2){
	printf(2, "need 2 arguments\n");
	}
	if((f = open(argv[1], O_CREATE)) < 0){
		printf(1, "touch: %s failed to create\n", argv[1]);
	}
	exit();
}
