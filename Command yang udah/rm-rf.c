#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

void rm (char * *argv[])
{
      if(unlink(*argv[]) < 0)
      {
        printf(2, "rm: %s failed to delete\n", *argv[]);
        return;
    }
}

void rmrf (char *path)
{
  char buf[512], *p;
  int fd;
  struct dirent de;
  struct stat st;

  if((fd = open(path, 0)) < 0)
  {
    printf(2, "ls: cannot open %s\n", path);
    return;
  }

  if(fstat(fd, &st) < 0)
  {
    printf(2, "ls: cannot stat %s\n", path);
    close(fd);
    return;
  }

  switch(st.type)
  {
    case T_FILE:

      rm (path);
      break;

    case T_DIR:
      if(strlen(path) + 1 + DIRSIZ + 1 > sizeof buf)
      {
        
	
        break;
      }
    strcpy(buf, path);
      p = buf+strlen(buf);
      *p++ = '/';
        while(read(fd, &de, sizeof(de)) == sizeof(de))
        {
          if(de.inum == 0 || strcmp(de.name, ".") == 0 || strcmp(de.name, "..") == 0) 
          continue;
          memmove(p, de.name, strlen(de.name));
          p[strlen(de.name)] = 0;

          if(stat(buf, &st) < 0)
          {
            printf(1, "ls: cannot stat %s\n", buf);
            continue;
          }
          
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
        break;
  }
  close(fd);
}

int main(int argc, char *argv[])
{
 int i;

  if(argc < 2)
  {
    printf(2, "Usage: rm files...\n");
    exit();
  }


  
  
  if(strcmp(argv[1],"-rf") == 0)
  {
    for (i = 2; i < argc; i++)
    {
      rmrf(argv[i]);
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


