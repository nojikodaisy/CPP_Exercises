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
RGBA convert<RGBA, RGBA>(const RGBA& x)
{
    return x;
}

template <>
RGB convert<RGB, RGB>(const RGB& x)
{
    return x;
}

template <>
Luma convert<Luma, Luma>(const Luma& x)
{
    return x;
}

template <>
RGB convert<RGB, RGBA>(const RGBA& x)
{
    return { x.r, x.g, x.b };
}

template <>
RGBA convert<RGBA, RGB>(const RGB& x)
{
    return { x.r, x.g, x.b, 255 };
}

template <>
Luma convert<Luma, RGB>(const RGB& x)
{
    return { image_lib::rgb_to_grayscale(x.r, x.g, x.b) };
}

template <>
RGB convert<RGB, Luma>(const Luma& x)
{
    auto [r, g, b] = image_lib::grayscale_to_rgb(x.g);
    return RGB { r, g, b };
}

template <>
Luma convert<Luma, RGBA>(const RGBA& x)
{
    return convert<Luma, RGB>(convert<RGB, RGBA>(x));
}

template <>
RGBA convert<RGBA, Luma>(const Luma& x)
{
    return convert<RGBA, RGB>(convert<RGB, Luma>(x));
}

RGBA operator+(const RGBA& lhs, const RGBA& rhs)
{
    auto [r, g, b, a] = image_lib::mix_color(lhs.r, lhs.g, lhs.b, lhs.a, rhs.r, rhs.g, rhs.b, rhs.a);
    return RGBA { r, g, b, a };
}

RGB operator+(const RGB& lhs, const RGBA& rhs)
{
    return convert<RGB, RGBA>(convert<RGBA, RGB>(lhs) + rhs);
}

RGB operator+(const Luma& lhs, const RGBA& rhs)
{
    return convert<RGB, Luma>(lhs) + rhs;
}

RGBA operator+(const RGBA& lhs, const RGB& rhs)
{   
    return lhs + convert<RGBA, RGB>(rhs);
}

RGB operator+(const RGB& lhs, const RGB& rhs)
{
    return lhs + convert<RGBA>(rhs);
}

RGB operator+(const Luma& lhs, const RGB& rhs)
{
    return convert<RGB, Luma>(lhs) + rhs;
}

template <typename P>
RGBA operator+(const P& lhs, const Luma& mask)
{
    RGBA lhs_rgba = convert<RGBA>(lhs);
    return RGBA { lhs_rgba.r, lhs_rgba.g, lhs_rgba.b, static_cast<uint8_t>(lhs_rgba.a * mask.g / 255) };
}
