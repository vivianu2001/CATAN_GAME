#ifndef RESOURCE_HPP
#define RESOURCE_HPP

class Resource
{
public:
    enum Type
    {
        WOOD,
        BRICK,
        WOOL,
        GRAIN,
        ORE,
        NONE
    };

    Resource(Type type) : type(type) {}

    Type getType() const { return type; }

private:
    Type type;
};

#endif // RESOURCE_HPP
