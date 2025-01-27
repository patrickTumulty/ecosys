
#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include "component.hpp"
#include "entity.hpp"
#include <cstdint>
#include <memory>
#include <optional>
#include <set>
#include <vector>

namespace ecosys
{
    class EntityManager
    {
    public:
        EntityManager() = default;

        void newEntity(std::initializer_list<std::shared_ptr<Component>> components);

        void addComponent(uint32_t entityIndex, std::shared_ptr<Component> component);

        void removeComponent(uint32_t entityIndex, std::shared_ptr<Component> component);

        void removeEntity(uint32_t entityIndex);

        template<typename T>
        bool entityHasComponent(uint64_t entityIndex)
        {
            auto entityOptional = findEntity(entityIndex);
            if (entityOptional.has_value())
            {
                return entityOptional.value()->hasComponent<T>();
            }
            return false;
        }

        template<typename T>
        std::vector<std::shared_ptr<T>> queryEntities()
        {
            std::vector<std::shared_ptr<T>> collection;
            for (auto entity : entities)
            {
                std::shared_ptr<T> t = entity->getComponent<T>();
                if (t == nullptr)
                {
                    continue;
                }

                collection.push_back(t);
            }
            return collection;
        }

        template<typename T, typename V>
        std::vector<std::tuple<std::shared_ptr<T>, std::shared_ptr<V>>> queryEntities()
        {
            std::vector<std::tuple<std::shared_ptr<T>, std::shared_ptr<V>>> collection;
            for (auto entity : entities)
            {
                std::shared_ptr<T> t = entity->getComponent<T>();
                if (t == nullptr)
                {
                    continue;
                }

                std::shared_ptr<V> v = entity->getComponent<V>();
                if (v == nullptr)
                {
                    continue;
                }

                collection.push_back({t, v});
            }
            return collection;
        }

        template<typename T, typename V, typename K>
        std::vector<std::tuple<std::shared_ptr<T>, std::shared_ptr<V>, std::shared_ptr<K>>> queryEntities()
        {
            std::vector<std::tuple<std::shared_ptr<T>, std::shared_ptr<V>, std::shared_ptr<K>>> collection;
            for (auto entity : entities)
            {
                std::shared_ptr<T> t = entity->getComponent<T>();
                if (t == nullptr)
                {
                    continue;
                }

                std::shared_ptr<V> v = entity->getComponent<V>();
                if (v == nullptr)
                {
                    continue;
                }

                std::shared_ptr<K> k = entity->getComponent<K>();
                if (k == nullptr)
                {
                    continue;
                }

                collection.push_back({t, v, k});
            }
            return collection;
        }

    private:
        std::optional<std::shared_ptr<Entity>> findEntity(uint32_t entityIndex);

        std::set<uint32_t> availableIndexSet;
        std::vector<std::shared_ptr<Entity>> entities;
    };
}// namespace ecosys


#endif
