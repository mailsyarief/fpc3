#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int i;

  if(argc < 2){
    printf(2, "Usage: rm files...\n");
    exit();
  }

  for(i = 1; i < argc; i++){
    if(unlink(argv[i]) < 0){
      printf(2, "rm: %s failed to delete\n", argv[i]);
      break;
    }
  }

  exit();
}

void rm (char * argv[]){
	if(unlink(argv[i]) < 0){
    printf(2, "rm: %s failed to delete\n", argv[i]);
    break;
    }
}

void rmrf(char *path)
{
  char buf[512], *p;
  int fd;
  struct dirent de;
  struct stat st;

  if((fd = open(path, 0)) < 0){
    //printf(2, "ls: cannot open %s\n", path);
    return;
  }

  if(fstat(fd, &st) < 0){
    //printf(2, "ls: cannot stat %s\n", path);
    close(fd);
    return;
  }

  switch(st.type){
  case T_FILE:
    //printf(1, "%s %d %d %d\n", fmtname(path), st.type, st.ino, st.size);
    break;

  case T_DIR:
    if(strlen(path) + 1 + DIRSIZ + 1 > sizeof buf){
      printf(1, "ls: path too long\n");
      break;
    }
    strcpy(buf, path);
    p = buf+strlen(buf);
    *p++ = '/';
    while(read(fd, &de, sizeof(de)) == sizeof(de)){
      if(de.inum == 0)
        continue;
      memmove(p, de.name, DIRSIZ);
      p[DIRSIZ] = 0;
      if(stat(buf, &st) < 0){
        printf(1, "ls: cannot stat %s\n", buf);
        continue;
      }
      //printf(1, "%s %d %d %d\n", fmtname(buf), st.type, st.ino, st.size);
      if(st.type == T_FILE)
          {
            rm(buf);
          }
          else if (st.type == T_DIR)
          {
            rmrf(buf);
          }
        }
         if(unlink(path) < 0)
        {
          printf(1, "Unable to remove %s", path);
        }
    }
    break;
  }
  close(fd);
}

int
main(int argc, char *argv[])
{
  int i;

  if(argc < 2){
    printf(2, "Usage: rm files...\n");
    exit();
  }
  
  if(strcmp(argv[1],"-rf") == 0)
  {
    for (i = 2; i < argc; i++)
    {
      rm_rekrusif(argv[i]);
    }
      exit();
  }
  

  for(i = 1; i < argc; i++)
  {
    if(unlink(argv[i]) < 0)
    {
      printf(2, "rm: %s failed to delete\n", argv[i]);
      break;
    }
    }
  exit();
}

