#include "libtush.h"
#include <stdio.h>

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
