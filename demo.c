#include "libtush.h"

void cmd_tryme()
{

}

int main()
{
  const struct tush_cmd cmds[] = {
    {.cmd = "tryme", .desc = "Try Me", .cmd_fn = cmd_tryme},
    {}
  };

  struct tush_t tush = {
    .cmds = cmds,
  };

  tush_init(&tush);
  return 0;
}
