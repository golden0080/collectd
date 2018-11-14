#include "common.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern char *hostname_g;

const int max_zeno_file_size = 5120;
const char * delim = "{}:, \n\r\t";
const char * quotes = "\"\'";

int turing_hostname_set(char const *zeno_file) {
  char *file_buffer = NULL;
  int file_len = 0;

  file_buffer = (char *) calloc(max_zeno_file_size + 1, sizeof(char));
  file_len = read_file_contents(zeno_file, file_buffer, max_zeno_file_size);
  if (file_len <= 0) return 0;

  char *token, *value;
  token = strtok(file_buffer, delim);
  while (token) {
    if (strcasecmp(token, "\"device_id\"") == 0) {
      // Get next token, which is the value
      token = strtok(NULL, delim);
      if (token) {
        value = strtok(token, quotes);

        if (value) {
          hostname_set(value);
          return 1;
        }
        return 0;
      }
    }
    token = strtok(NULL, delim);
  }
  return 0;
}
