#include <unistd.h>
 
int main(void)
{
    write(1, "Hello, C\n", 9);
    return 0;
}
