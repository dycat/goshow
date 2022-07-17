#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <glib.h>
#include <goshow.h>


show *show_new(char *show_name, bool is_finish_watch){
    show *new = malloc(sizeof(show));
    new->show_name = show_name;
    new->is_finish_watch = is_finish_watch;

    return new;
}

show *show_copy(show const *in){
    show *out = malloc(sizeof(show));
    *out = *in;

    return out;
}

void show_free(show *in){
    free(in);
}

/*
print type show
*/
void show_print(show *in){
    printf("---------\n");
    printf("Show Name: %s\n", in->show_name);
    printf("Watched: %s\n", in->is_finish_watch ? "看过" : "没看完");
    printf("---------\n");
}

int main() {
    show *ep1 = show_new("打工吧，魔王大人！第二季", false);
    show *ep2 = show_new("Spy x family", true);

    GList *list = NULL;
    list = g_list_append(list, ep1);
    list = g_list_append(list, ep2);

    int list_length = g_list_length(list);
    int i;
    for(i = 0; i < list_length; i++){
        show *ep = g_list_nth_data(list, i);
        show_print(ep);
    }

    show_free(ep1);
    free(list);
}
