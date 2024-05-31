#include <unistd.h>

void function(char c);

int main() {

    function('a');  // Call function to print 'A'
    return 0;
}
void function(char c) {
    write(1, &c, 1);  // Write the character c to stdout
}
