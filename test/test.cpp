#include <mapbox/util/geometry.hpp>
#include "tap.hpp"


int main() {
    Tap tap;

    {
        Tap::Test t("empty");
        t.ok(true, "true");
        t.end();
    }

    return 0;
}