#include <stdlib.h>
#include "../../../src/util/mem/str.h"
#include "../../../src/util/unit/unit.h"

void shouldCreateNewString(unit_T *t) {
    char *old = "This is a string!";
    char *new = mem_newString(old);

    UNIT_ASSERT_EQS(t, old, new);

    free(new);
}

void mem_string(unit_S *s) {
    unit_test(s, shouldCreateNewString);
}

