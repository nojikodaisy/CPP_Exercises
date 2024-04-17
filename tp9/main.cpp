#include <functional>
#include <unordered_map>
#include <cassert>
#include <iostream>
#include <set>
#include <tuple>

enum class Content { Empty, Red, Yellow };

struct Point2d
{   
    Point2d(int x, int y) :
    _x { x },
    _y { y }
    {}
    int _x;
    int _y;

    bool operator==(const Point2d& other) const {
        return _x == other._x && _y == other._y;
    }
   
};

class Point2dHash
{
public:
    std::size_t operator()(const Point2d& p) const {
        std::size_t h1 = std::hash<int>{}(p._x);
        std::size_t h2 = std::hash<int>{}(p._y);
        return h1 ^ (h2 << 1); 
    }
};

namespace std {   // il faut se placer dans le bon namespace

template <>
struct hash<Point2d>
{
   std::size_t operator()(const Point2d& p) const {
        std::size_t h1 = std::hash<int>{}(p._x);
        std::size_t h2 = std::hash<int>{}(p._y);
        return h1 ^ (h2 << 1); 
    }
};

}

class Point2dEqual 
{   
public:
    bool operator()(const Point2d& p1, const Point2d& p2) const {
        return (p1._x == p2._x) && (p1._y == p2._y);
    }
};


struct Point3d
{   
    Point3d(int x, int y, int z) :
    _x { x },
    _y { y },
    _z { z }
    {}

    /*
    bool operator==(const Point2d& other) const {
        return _x == other._x && _y == other._y;
    }
    */
    int _x;
    int _y;
    int _z;

    bool operator<(const Point3d& p2) const {
       return std::tie(_x, _y, _z) < std::tie(p2._x, p2._y, p2._z);
    }
};

class Point3dCompare {
public:
    bool operator()(const Point3d& p1, const Point3d& p2) const {
        return std::tie(p1._x, p1._y, p1._z) < std::tie(p2._x, p2._y, p2._z);
    }
};


int main(int argc, char const *argv[])
{
    /*std::unordered_map<Point2d, Content> grid;
    grid[{1, 2}] = Content::Red;
    grid[{1, 2}] = Content::Yellow;
    assert((grid[{1, 2}] == Content::Yellow));
    */
    std::set<Point3d> coords;
    coords.emplace(1, 2, 3);
    coords.insert({2, 4, 6});

    for (const auto& point : coords)
    {
        std::cout << point._x << " " << point._y << " " << point._z << std::endl;
    }
    std::cout << "oe" << std::endl;
    return 0;
}

