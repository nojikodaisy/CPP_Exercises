#pragma once

#include <array>
#include <functional>

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

    const Image& operator+(const Image& other) {
        Image<P, W, H> image;
        for(auto i = 0; i < W; i++) {
            for (auto j = 0; j < H; j++) {
                image(i, j) = this(i, j) + other(i, j);
            }
        }
        return image;
    }

    

private:
    std::array<std::array<P, W>, H> _pixels;
};