
#include "ecosys/component.hpp"

using namespace ecosys;

void Component::setEntityIndex(uint32_t entityIndex)
{
    this->entityIndex = entityIndex;
}

uint32_t Component::getEntityIndex()
{
    return entityIndex;
}
