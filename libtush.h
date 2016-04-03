typedef int (*tush_iofn)(char * buf, int cnt);
struct tush_cmd {
  const char * cmd;
  const char * desc;
  const void * cmd_fn;
};
struct tush_t {
  const struct tush_cmd * cmds;
};
void tush_init(struct tush_t * tush);
void tush_go(struct tush_t * tush, tush_iofn read, tush_iofn write);
