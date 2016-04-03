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
}
