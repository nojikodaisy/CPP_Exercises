#include "../lib/image_lib.hpp"
#include "image.hpp"

#include <cassert>

int main()
{
    const auto image = Image<uint8_t, 800, 600> { 128 };
    for (size_t i = 0; i < 800; ++i)
        for (size_t j = 0; j < 600; ++j)
            assert(image(i, j) == 128u);
    image_lib::save(image, "images/midgray.png"); // Ouvrez moi !!
    return 0;
}
