#include "libtush.h"

void tush_cmd_help()
{

}

void tush_reg_cmd(struct tush_t * tush, char * cmd, char * desc, void * cmd_fn)
{

}

void tush_init(struct tush_t * tush)
{
  tush_reg_cmd(tush, "help", "list all commands", tush_cmd_help);
  const struct tush_cmd * cmd = tush->cmds;
  while(cmd->cmd) {
    printf("command %s\r\n", cmd->cmd);
    cmd++;
  }
}

void tush_go(struct tush_t * tush, tush_iofn read, tush_iofn write)
{
  char c;
  while(2) {
    if (write("woot\r\n", 6) == -1)
      break;
    printf("read %i %c\r\n", read(&c, 1), c);
  }

}
