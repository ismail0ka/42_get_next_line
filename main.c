#include <fcntl.h>
#include "get_next_line.h"

int main(){
    int f_fd = open("test.txt", O_RDWR | O_CREAT);
    char   *s;
    
    while ((s = get_next_line(f_fd)))
    {   
        if (!s)
            break ;
        printf("%s\n",s);
    }
    printf("(NULL)0");
    return 0;
}
