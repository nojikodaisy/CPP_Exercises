#pragma once
#include "../lib/image_lib.hpp"

struct RGBA {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

struct RGB {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct Luma {
    uint8_t g;
};

template <typename To, typename From>
To convert(const From& stuff);

template <>
RGBA convert<RGBA, RGB>(const RGB& x)
{
    return { x.r, x.g, x.b, 255 };
}

template <typename From>
From convert(const From& x)
{
    return x;
}

template <>
RGB convert<RGB, RGBA>(const RGBA& x)
{
    return { x.r, x.g, x.b };
}

template <>
Luma convert<Luma, RGB>(const RGB& x)
{
    return { image_lib::rgb_to_grayscale(x.r, x.g, x.b) };
}

template <>
RGB convert<RGB, Luma>(const Luma& x)
{   
    auto rgb = image_lib::grayscale_to_rgb(x.g);
    return { rgb[0], rgb[1], rgb[2] };
}

template <>
Luma convert<Luma, RGBA>(const RGBA& x)
{
    return convert<Luma>(convert<RGB>(x));
}

template <>
RGBA convert<RGBA, Luma>(const Luma& x)
{
    return convert<RGBA>(convert<RGB>(x));
}

RGBA operator+(const RGBA& lhs, const RGBA& rhs)
{
    // TODO
    auto mix = image_lib::mix_color(lhs.r, lhs.g, lhs.b, lhs.a, rhs.r, rhs.g, rhs.b, rhs.a);
    return { mix[0], mix[1], mix[2], mix[4] };
}

RGB operator+(const RGB& lhs, const RGBA& rhs)
{
    auto rgb = convert<RGBA>(lhs);
    return convert<RGB>(rgb + rhs);
}

RGB operator+(const Luma& lhs, const RGBA& rhs)
{
    auto rgb = convert<RGBA>(lhs);
    return convert<RGB>(rgb + rhs);
}

RGBA operator+(const RGBA& lhs, const RGB& rhs)
{
    return convert<RGBA>(rhs) + lhs;
}

RGB operator+(const RGB& lhs, const RGB& rhs)
{
    auto rgb1 = convert<RGBA>(lhs);
    auto rgb2 = convert<RGBA>(rhs);
    return convert<RGB>(rgb1 + rgb2);
}

RGB operator+(const Luma& lhs, const RGB& rhs)
{
    auto rgb1 = convert<RGBA>(lhs);
    auto rgb2 = convert<RGBA>(rhs);
    return convert<RGB>(rgb1 + rgb2);
}



