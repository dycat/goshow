#include <stdbool.h>

typedef struct {
    char *show_name;
    bool is_finish_watch;
} show;

show *show_new(char *show_name, bool is_finish_watch);
show *show_copy(show const *in);
void show_free(show *in);
