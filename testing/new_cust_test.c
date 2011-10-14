#include <allocate.h>
#include "types.h"
#include "customers.h"

int main(void){
    
    Customer *c;

    c = allocate(sizeof(Customer));

    return 0;

}
