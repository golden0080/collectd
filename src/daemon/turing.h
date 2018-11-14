#ifndef TURING_H
#define TURING_H

/* turing_hostname_set updates hostname_g, after reading zeno config file */
// 1 means value set, 0 means value not set
int turing_hostname_set(char const *zeno_config_file);

#endif /* TURING_H */
