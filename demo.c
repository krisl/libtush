#include "libtush.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define _XOPEN_SOURCE 600
void cmd_tryme()
{

}

static int fd;
int demo_read(char * buf, int cnt)
{
  return read(fd, buf, cnt);
}

int demo_write(char * buf, int cnt)
{
  return write(fd, buf, cnt);
}

int main()
{
  const struct tush_cmd cmds[] = {
    {.cmd = "tryme", .desc = "Try Me", .cmd_fn = cmd_tryme},
    {}
  };

  struct tush_t tush = {
    .cmds = cmds,
    //.read = demo_read,
    //.write = demo_write,
  };

  tush_init(&tush);

  fd = posix_openpt(O_RDWR | O_NOCTTY);
  if (grantpt(fd)) {
    printf("Error on grant\r\n");
    return -1;
  }

  if (unlockpt(fd)) {
    printf("Error on unlock\r\n");
    return -2;
  }

  printf("Open console at %s\r\n", ptsname(fd));
  
  tush_go(&tush, demo_read, demo_write);
  return 0;
}
