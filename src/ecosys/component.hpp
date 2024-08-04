
#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <cstdint>

namespace ecosys
{
    class Component
    {
    public:
        virtual ~Component() = default;

        virtual void setEntityIndex(uint32_t entityUid);

        uint32_t getEntityIndex();

    private:
        uint32_t entityIndex;
    };
}// namespace ecosys


#endif
