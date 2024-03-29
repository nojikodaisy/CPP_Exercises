#include <functional>
#include <unordered_map>
#include <cassert>

enum class Content { Empty, Red, Yellow };

struct Point2d
{   
    Point2d(int x, int y) :
    _x { x },
    _y { y }
    {}
    int _x;
    int _y;
   
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

class Point2dEqual 
{   
public:
    bool operator()(const Point2d& p1, const Point2d& p2) const {
        return (p1._x == p2._x) && (p1._y == p2._y);
    }
};


int main(int argc, char const *argv[])
{
    std::unordered_map<Point2d, Content, Point2dHash, Point2dEqual> grid;
    grid[{1, 2}] = Content::Red;
    grid[{1, 2}] = Content::Yellow;
    assert((grid[{1, 2}] == Content::Yellow));
    return 0;
}

