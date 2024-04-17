#pragma once

#include <array>
#include <functional>

template <typename P1, typename P2>
using CombinedPixel = decltype(std::declval<P1>() + std::declval<P2>());


template<typename P, size_t W, size_t H>
class Image {
public:
    Image() = default;

    Image(const P& pixel) {
        for(auto i = 0; i < H; i++) {
            for (auto j = 0; j < W; j++) {
                _pixels[i][j] = pixel;
            }
        }
    }

    Image(const std::function<P(size_t i, size_t j)>& functor) {
        for(auto i = 0; i < H; i++) {
            for (auto j = 0; j < W; j++) {
                _pixels[i][j] = functor(i, j);
            }
        }
    }

    const P& operator()(size_t i, size_t j) const {
        return _pixels[j][i];
    } 

    P& operator()(size_t i, size_t j) {
        return _pixels[j][i];
    } 

    template <typename OtherP>
    Image<CombinedPixel<P, OtherP>, W, H> operator+(const Image<OtherP, W, H>& other) const
    {
        Image<CombinedPixel<P, OtherP>, W, H> res;
        for (size_t i = 0; i < W; i++)
        {
            for (size_t j = 0; j < H; j++)
            {
                res(i, j) = _pixels[j][i] + other(i, j);
            }
        }
        return res;
    }
    

private:
    std::array<std::array<P, W>, H> _pixels;
};